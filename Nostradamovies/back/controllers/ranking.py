import operator
import pandas as pd
from flask import jsonify

class Ranking:
  def __init__(self, df):
    self.df = df

  def get_top_genres(self, type: str, sort_by: str):
    series = self.df[type] \
      .str \
      .split(pat=",", expand=True) \
    
    crosstab = pd.crosstab(**series.melt(var_name='columns', value_name='index'))
    genres = {}

    for name, data in crosstab.iterrows():
      movieName = name.strip()
      values = data.values.sum()

      if movieName in genres.keys():
        genres[movieName] += values
      else:
        genres[movieName] = values

    return dict(sorted(
      genres.items(),
      key=operator.itemgetter(1),
      reverse=True if sort_by == 'desc' else False
    ))

  def get_nb_movies_by(self, type, options):
    filtered_df = self.df[self.df['genre'].str.contains(options['genre'])] if options.get('genre') != None else self.df
    nb_movies_based_on_year = filtered_df[type].value_counts()
    years = {}

    for year, value in nb_movies_based_on_year.items():
      years[year] = value
    
    sorted_dict = dict(sorted(
      years.items(),
      key=operator.itemgetter(1),
      reverse=True if options.get("sort_by") != 'asc' else False
    ))

    return sorted_dict