from datasets import (
    Dataset,
    Client,
    ClientSegmenter,
    Families,
    Meshes,
    Products,
    TicketDetails,
    Tickets,
    Universes
)
from flask import Flask, jsonify, request
from flask_cors import CORS
from flask_restful import abort, Api
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA

import config
import pandas as pd
import pickle

app = Flask(__name__)
CORS(app)
api = Api(app)
df = pd.read_hdf(config.DATASET_HDF5_PATH)
client_summary_df = pd.read_hdf(config.CLIENT_DATASET_HDF5_PATH)
ticket_summary_df = pd.read_hdf(config.TICKET_DATASET_HDF5_PATH)

with open(config.PCA_MODEL_PATH, "rb") as f:
    pca = pickle.load(f)

with open(config.CLUSTER_MODEL_PATH, "rb") as f:
    cluster_model = pickle.load(f)

CLIENT_FILTER_DISTINCT = 'distinct'
CLIENT_FILTER_RETURNING = 'returning'


@app.route('/')
def hello_world():  # put application's code here
    return 'Recommender API'


@app.route('/dataset/stats')
def get_dataset_stats():
    dataset = Dataset(df)
    total_clients = dataset.get_clients_amount()
    total_products = dataset.get_products_amount()
    total_products_sold = dataset.get_products_sold_amount()
    total_amount_spent = dataset.get_total_amount_spent()
    total_amount_spent_by_month_average = dataset.get_amount_spent_by_month_average()

    return jsonify([
        {'title': 'Total Clients', 'value': int(total_clients)},
        {'title': 'Total Products', 'value': int(total_products)},
        {'title': 'Total Products Sold', 'value': int(total_products_sold)},
        {'title': 'Total amount spend', 'value': int(total_amount_spent), 'currency': True},
        {'title': 'Total amount spend by month in average', 'value': int(total_amount_spent_by_month_average), 'currency': True},
    ])


@app.route('/dataset/monthly-stats/amount')
def get_dataset_monthly_amount():
    dataset = Dataset(df)
    total_amount_spent_by_month = dataset.get_amount_spent_by_month()

    return jsonify(total_amount_spent_by_month)

@app.route('/clients/<int:client_id>/check')
def check_client(client_id: int):
    try:
        Client(df, client_id)

        return ('Client found.')
    except ValueError as e:
        print(e)
        abort(400)

@app.route('/clients/<int:client_id>/tickets')
def get_client(client_id: int):
    try:
        client = Client(df, client_id)
        tickets = Tickets(df)
        client_tickets = tickets.get_client_tickets(client)

        return jsonify({
            'client_id': str(client.client_id),
            'tickets': client_tickets
        })
    except ValueError as e:
        print(e)
        abort(400)

@app.route('/clients/<int:client_id>/tickets/monthly-global-data')
def get_client_tickets_monthly_global_data(client_id: int):
    try:
        client = Client(df, client_id)
        tickets = Tickets(df)
        client_tickets = tickets.get_client_tickets_monthly_global_data(client)

    except ValueError as e:
        abort(400)

@app.route('/clients/<int:client_id>/segment')
def client_segment(client_id: int):
    try:
        print(df['CLI_ID'].nunique())
        client = Client(df, client_id)
        segmenter = ClientSegmenter(client_summary_df, pca, cluster_model)
        segment = segmenter.get_client_segment(client)

        return jsonify({
            'segment': segment
        })
    except ValueError as e:
        print(e)
        abort(400)


@app.route('/clients/<int:client_id>/stats')
def client_stats(client_id: int):
    try:
        client = Client(df[df['CLI_ID'] == client_id], client_id)
        stats = client.get_client_stats()
        return jsonify(stats)
    except ValueError as e:
        print(e)
        abort(400)


@app.route('/clients/<int:client_id>/products')
def get_client_top_products(client_id: int):
    try:
        client = Client(df[df['CLI_ID'] == client_id], client_id)
        top_products = client.get_top_products()
        return jsonify(top_products)
    except ValueError as e:
        print(e)
        abort(400)


@app.route('/families')
def list_families():
    families = Families(df).list()
    return jsonify(families)


@app.route('/families/sales')
def family_sales():
    family_counts = Families(df).get_sales()
    return jsonify(family_counts)


@app.route('/families/stats')
def family_stats():
    args = request.args
    family_filter = args.get('type', None, str)
    print(family_filter)
    families = Families(df)

    if not family_filter:
        abort(400)

    stats = families.get_family_stats(family_filter)
    return jsonify(stats)


@app.route('/families/monthly-sales/<int:month>')
def family_month_sales(month: int):
    if month not in range(1, 13):
        abort(400)
    family_counts = Families(df).get_monthly_sales(month)
    return jsonify(family_counts)


@app.route('/universes')
def list_universes():
    universes = Universes(df).list()
    return jsonify(universes)


@app.route('/universes/stats')
def universe_stats():
    args = request.args
    universe_filter = args.get('type', None, str)
    universes = Universes(df)

    if not universe_filter:
        abort(400)

    stats = universes.get_universe_stats(universe_filter)
    return jsonify(stats)


@app.route('/universes/sales')
def universe_sales():
    universe_counts = Universes(df).get_sales()
    return jsonify(universe_counts)


@app.route('/universes/monthly-sales/<int:month>')
def universe_month_sales(month: int):
    if month not in range(1, 13):
        abort(400)
    universe_counts = Universes(df).get_monthly_sales(month)
    return jsonify(universe_counts)


@app.route('/meshes')
def list_meshes():
    meshes = Meshes(df).list()
    return jsonify(meshes)


@app.route('/meshes/stats')
def mesh_stats():
    args = request.args
    universe_filter = args.get('type', None, str)
    meshes = Meshes(df)

    if not universe_filter:
        abort(400)

    stats = meshes.get_mesh_stats(universe_filter)
    return jsonify(stats)


@app.route('/meshes/sales')
def mesh_sales():
    mesh_counts = Meshes(df).get_sales()
    return jsonify(mesh_counts)


@app.route('/meshes/monthly-sales/<int:month>')
def mesh_month_sales(month: int):
    if month not in range(1, 13):
        abort(400)
    mesh_counts = Meshes(df).get_monthly_sales(month)
    return jsonify(mesh_counts)


# [TODO] Add in pagination for better load times
@app.route('/products')
def list_products():
    products = Products(df).list()
    return jsonify(products)


@app.route('/products/top-products')
def get_top_products():
    products = Products(df)
    top_products = products.top_products()
    return jsonify(top_products)


@app.route('/products/top-monthly-products/<int:month>')
def get_top_monthly_products(month: int):
    if month not in range(1, 13):
        abort(400)
    products = Products(df)
    top_products = products.top_monthly_products(month)
    return jsonify(top_products)


# @app.route('/products/count')
# def product_count():
#     products = json.loads(Products(df).list())
#     return jsonify(products)

@app.route('/tickets/<int:ticket_id>/info')
def ticket_info(ticket_id: int):
    tickets = TicketDetails(df)
    details = tickets.get_ticket_details(ticket_id)
    return jsonify(details)


@app.route('/tickets/stats')
def ticket_stats():
    tickets = Tickets(ticket_summary_df)
    stats = tickets.get_ticket_stats()
    return jsonify(stats)


@app.route('/tickets/clients/monthly-counts')
def get_client_counts():
    args = request.args
    client_filter = args.get('clients', None, str)
    tickets = Tickets(ticket_summary_df)

    if client_filter == CLIENT_FILTER_DISTINCT:
        ticket_counts = tickets.get_monthly_distinct_client_counts()
    elif client_filter == CLIENT_FILTER_RETURNING:
        ticket_counts = tickets.get_monthly_returning_client_counts()
    else:
        ticket_counts = tickets.get_monthly_client_counts()

    return jsonify(ticket_counts)


if __name__ == '__main__':
    app.run(debug=True)
