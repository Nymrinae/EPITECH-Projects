from dash import dcc, html
from dash.dependencies import Output, Input

import calendar

from pandas.core.frame import DataFrame
import configs.visualizers.dash_visualizer_config as vconfig
import dash
import pandas as pd


def getMonthPurchases(df: pd.DataFrame, monthNbr: str):
    return df.loc[df["MOIS_VENTE"] == monthNbr]


def getCategoryTypePurchase(df: pd.DataFrame, category: str, categoryType: str):
    return df.loc[df[category] == categoryType]


def getColumnValueCounts(df: pd.DataFrame, column: str):
    return df[column].value_counts()


def getColumnUniqueValues(df: pd.DataFrame, column: str):
    return df[column].unique()

df = pd.read_hdf(vconfig.DATASET_PATH, vconfig.DATASET_KEY)

app = dash.Dash(__name__)

app.layout = html.Div([
    html.Div(
        children=[
            html.Div(
                children=[
                    html.Div(
                        children=[
                            html.Div(children="Category",
                                     className="menu-title"),
                            dcc.Dropdown(
                                id="category-counts--category-filter",
                                options=[
                                    {
                                        "label": "Famille",
                                        "value": "FAMILLE"
                                    },
                                    {
                                        "label": "Univers",
                                        "value": "UNIVERS"
                                    },
                                    {
                                        "label": "Maille",
                                        "value": "MAILLE"
                                    }
                                ],
                                value=vconfig.DEFAULT_CATEGORY,
                                clearable=False,
                                className="dropdown",
                            ),
                        ]
                    ),
                    html.Div(
                        children=[
                            html.Div(children="Month", className="menu-title"),
                            dcc.Dropdown(
                                id="category-counts--month-filter",
                                options=[
                                    {"label": month, "value": idx + 1} for idx, month in enumerate(calendar.month_name[1:])
                                ],
                                value=vconfig.DEFAULT_MONTH,
                                clearable=False,
                                className="dropdown",
                            ),
                        ]
                    )
                ],
                className="menu",
            ),
            html.Div(
                children=[
                    dcc.Graph(id="category-counts-chart")
                ]
            )
        ]
    ),
    html.Div(
        children=[
            html.Div(
                children=[
                    html.Div(
                        children=[
                            html.Div(children="Category",
                                     className="menu-title"),
                            dcc.Dropdown(
                                id="category-evolution--category-filter",
                                options=[
                                    {
                                        "label": "Famille",
                                        "value": "FAMILLE"
                                    },
                                    {
                                        "label": "Univers",
                                        "value": "UNIVERS"
                                    },
                                    {
                                        "label": "Maille",
                                        "value": "MAILLE"
                                    }
                                ],
                                value=vconfig.DEFAULT_CATEGORY,
                                clearable=False,
                                className="dropdown",
                            ),
                        ]
                    ),
                    html.Div(
                        children=[
                            html.Div(children="Type", className="menu-title"),
                            dcc.Dropdown(
                                id="category-evolution--type-filter",
                                value=vconfig.DEFAULT_MONTH,
                                clearable=False,
                                className="dropdown",
                            ),
                        ]
                    )
                ],
                className="menu",
            ),
            html.Div(
                children=[
                    dcc.Graph(id="category-evolution-chart")
                ]
            )
        ]
    )
])

@app.callback(
    [Output("category-counts-chart", "figure")],
    [
        Input("category-counts--category-filter", "value"),
        Input("category-counts--month-filter", "value")
    ]
)
def updateCategoryCountChart(category: str, month: int):
    filteredPurchases = getMonthPurchases(df, month)
    itemCounts = getColumnValueCounts(
        filteredPurchases, category).sort_values(ascending=True)

    formattedCategory = category.lower().capitalize()
    formattedMonth = calendar.month_name[month]

    print(itemCounts.to_json())

    category_counts_figure = {
        "data": [
            {
                "x": itemCounts.index.tolist(),
                "y": itemCounts.to_list(),
                "cliponaxis": False,
                "text": itemCounts.to_list(),
                "texttemplate": "%{text:.2s}",
                "textposition": "outside",
                "type": "bar",
                # "hovertemplate": "$%{y:.2f}<extra></extra>",
            },
        ],
        "layout": {
            "title": {
                "text": f"Bar graph of purchases in the {formattedCategory} category during the month of {formattedMonth}",
            },
            "margin": {
                "b": 200
            },
            "uniformtext_minsize": 8,
            "uniformtext_mode": 'hide',
            "xaxis": {"fixedrange": True},
            "yaxis": {"fixedrange": True},
            "colorway": ["#17B897"],
        },
    }

    return [category_counts_figure]


@app.callback(
    [
        Output('category-evolution--type-filter', 'options'),
        Output('category-evolution--type-filter', 'value')
    ],
    Input('category-evolution--category-filter', 'value')
)
def updateCategoryEvolTypeOptions(category):
    types = getColumnUniqueValues(df, category)

    defaultValue = types[0]
    options = [{'label': i, 'value': i} for i in types]

    return options, defaultValue


@app.callback(
    [Output("category-evolution-chart", "figure")],
    [
        Input("category-evolution--category-filter", "value"),
        Input("category-evolution--type-filter", "value")
    ]
)
def updateCategoryEvolutionChart(category: str, categoryType: int):
    purchaseGroups = df.groupby(category)

    data = []
    for group, frame in purchaseGroups:
        purchasesPerMonth = getColumnValueCounts(
            frame, "MOIS_VENTE").sort_index(ascending=True)

        trace = {
            "x": purchasesPerMonth.index.tolist(),
            "y": purchasesPerMonth.tolist(),
            "cliponaxis": False,
            "mode": "lines",
            "name": group,
            "type": "line"
        }

        data.append(trace)

    category_evolution_figure = {
        "data": data,
        # [
        #     {
        #         "x": purchasesPerMonth.index.tolist(),
        #         "y": purchasesPerMonth.to_list(),
        #         "cliponaxis": False,
        #         # "text": itemCounts.to_list(),
        #         # "texttemplate": "%{text:.2s}",
        #         # "textposition": "outside",
        #         "type": "line",
        #         # "hovertemplate": "$%{y:.2f}<extra></extra>",
        #     },
        # ],
        "layout": {
            "title": {
                "text": "Test",
            },
            "margin": {
                "b": 200
            },
            "uniformtext_minsize": 8,
            "uniformtext_mode": 'hide',
            "xaxis": {"fixedrange": True},
            "yaxis": {"fixedrange": True},
            # "colorway": ["#17B897"],
        },
    }

    return [category_evolution_figure]


# purchases = df.groupby("FAMILLE")
# # purchases = getCategoryTypePurchases(df, category, categoryType)
# purchasesPerMonth = getColumnValueCounts(purchases, "MOIS_VENTE").sort_index(ascending=True)


# print(purchasesPerMonth)
app.run_server(debug=True)
# class DashVisualizer:
#     def __init__(self, df: pd.DataFrame):
#         self._app = dash.Dash(__name__)
#         self._df = df

#     def getCategoryItemCounts(self, category):
#         return self._df[category].value_counts().sort_values(ascending=True)

#     def buildLayout(self):
#         itemCounts = self.getCategoryItemCounts("FAMILLE")

#         self._app.layout = html.Div(
#             children=[
#                 dcc.Graph(
#                     figure={
#                         "data": [
#                             {
#                                 "x": itemCounts.index.tolist(),
#                                 "y": itemCounts.to_list(),
#                                 "type": "bar"
#                             },
#                         ],
#                         "layout": {"title": "Test"}
#                     }
#                 )
#             ]
#         )

#     def view(self, debug=True):
#         self._app.run_server(debug)
