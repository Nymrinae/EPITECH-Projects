from multiprocessing.sharedctypes import Value
from flask import Flask, jsonify, request, make_response
from flask_cors import CORS
from flask_restful import Api, abort
from itsdangerous import json
from numpy import short
import pandas as pd
import config
import json

from controllers import Movies, Ranking

app = Flask(__name__)
app.config['JSON_SORT_KEYS'] = False
CORS(app)
api = Api(app)

df = pd.read_hdf(config.DATASET_HDF5_PATH)
movies = Movies(df)
ranking = Ranking(df)

@app.route('/')
def home():
    # Add Swagger
    return 'Nostradamovies API'

@app.route('/dataset/stats')
def get_dataset_stats():
    total_movies = movies.get_movies_amount()
    longest_movie = movies.get_longest_movie()
    shortest_movie = movies.get_shortest_movie()
    movies_genres = movies.get_movies_genres()

    return jsonify(
        total_movies = total_movies,
        longest_movie = longest_movie[0],
        shortest_movie = shortest_movie[0],
        movies_genres = movies_genres
    )

@app.route('/dataset/stats/<key>')
def get_stats_based_on(key: str):
    try:
        return jsonify(movies.get_movies_based_on(key.lower()))
    except KeyError:
        abort(400)

@app.route('/movies')
def get_movies():
    try:
        search = request.args.get('search', default="", type=str)
        page = request.args.get('page', default=1, type=int)

        return movies.get_movies(search, page)
    except Exception as e:
        abort(400)

@app.route('/movies/details')
def get_movie_genre_details():
    try:
        genre = request.args.get('genre', default="", type=str)

        return movies.get_movie_genre_details(genre)
    except Exception as e:
        abort(400)

@app.route('/movies/<id>')
def get_movie_by_id(id: str):
    try:
        return jsonify(movies.get_movie_by_id(id))
    except:
        abort(400)

@app.route('/movies/upload', methods = ["POST"])
def upload_poster():
    try:
        file = request.form['file']

        data = {'message': 'File uploaded' }
        return make_response(jsonify(data), 200)
    except Exception as e:
        abort(400)


@app.route('/ranking/top-countries')
def get_top_countries():
    try:
        sort_by = request.args.get('sort_by', default="desc", type=str)

        return jsonify(ranking.get_top_genres('country', sort_by))
    except Exception as e:
        abort(400)

@app.route('/ranking/top-date')
def get_top_dates():
    try:
        sort_by = request.args.get('sort_by')

        return jsonify(ranking.get_nb_movies_by('year', { sort_by }))
    except:
        abort(400)

if __name__ == '__main__':
    app.run(debug=True)