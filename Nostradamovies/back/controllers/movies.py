import functools
import operator
import json

from flask import jsonify
from controllers.ranking import Ranking
from helpers.functions import value_counts_to_list

class Movies:
  def __init__(self, df):
    self.df = df
    self.ranking = Ranking(df)

  def get_movies_amount(self):
    return len(self.df)

  def get_movies_genres(self):
    genres = self.df['genre'].tolist()
    splitted_genres = [e.split(', ') for e in genres]

    return list(set(functools.reduce(operator.iconcat, splitted_genres, [])))

  def get_movies(self, search: str, page: int):
    page_offset = 24
    min = 1 if page == 1 else (page - 1) * page_offset + 1
    max = min + page_offset

    data = self.df[self.df['title'].str.contains(search, case=False)] if search else self.df

    return jsonify(
      min = min,
      max = max - 1,
      results = len(data) - 1,
      data = json.loads(data[min:max].to_json(orient="records"))
    )

  def get_movie_genre_details(self, genre):
    movies_with_genre_only = len(self.df[self.df['genre'] == genre])
    movies_with_at_least_genre = len(self.df[self.df['genre'].str.contains(genre)])

    return jsonify(
      genre = genre,
      movies_with_genre_only = movies_with_genre_only,
      movies_with_at_least_genre = movies_with_at_least_genre,
      movies_based_on_year = self.ranking.get_nb_movies_by('year', { "genre": None }),
      movies_based_on_country = self.ranking.get_nb_movies_by('country', { "genre": None }),
      movies_based_on_year_by_genre = self.ranking.get_nb_movies_by('year', { "genre": genre }),
      movies_based_on_country_by_genre = self.ranking.get_nb_movies_by('country', { "genre": genre })
    )

  def get_movies_based_on(self, key):
    return value_counts_to_list(self.df[key], key)
  
  def get_movie_by_id(self, id):
    return json.loads(self.df[self.df['imdb_title_id'] == id].to_json(orient="records"))

  def get_shortest_movie(self):
    min = self.df['duration'].min()
    
    return json.loads(self.df[self.df['duration'] == min].to_json(orient="records"))

  def get_longest_movie(self):
    max = self.df['duration'].max()

    return json.loads(self.df[self.df['duration'] == max].to_json(orient="records"))