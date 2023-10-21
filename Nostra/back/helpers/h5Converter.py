import pandas as pd
import os

DATASET_PATH = '../../data/dataset.csv'
OPTIMIZED_DATASET_PATH = '../data/dataset.h5'

df2 = pd.read_csv(DATASET_PATH)

if not os.path.exists('../data'):
  os.makedirs('../data')

df2.to_hdf(
  path_or_buf=OPTIMIZED_DATASET_PATH,
  key="df2",
  mode="w",
  format="table"
)