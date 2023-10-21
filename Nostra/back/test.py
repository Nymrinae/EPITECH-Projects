from pickle import TRUE
from numpy import flatiter
from controllers import Movies, Ranking
import functools
import operator
import pandas as pd
import config
from helpers.functions import value_counts_to_list

df = pd.read_hdf(config.DATASET_HDF5_PATH)

movies = Movies(df)
ranking = Ranking(df)

print(type(ranking.get_top_genres('country', 'desc')))