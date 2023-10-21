import pandas as pd

DATASET_PATH = '../data/KaDo.csv'
OPTIMIZED_DATASET_PATH = '../data/processed/KaDo.h5'

df2 = pd.read_csv(
    DATASET_PATH,
    dtype={
        "FAMILLE": "category",
        "LIBELLE": "category",
        "MAILLE": "category",
        "UNIVERS": "category"
    }
)

df2["CLI_ID"] = pd.to_numeric(df2["CLI_ID"], downcast="unsigned")
df2["MOIS_VENTE"] = pd.to_numeric(df2["MOIS_VENTE"], downcast="unsigned")
df2["PRIX_NET"] = pd.to_numeric(df2["PRIX_NET"], downcast="float")
df2["TICKET_ID"] = pd.to_numeric(df2["TICKET_ID"], downcast="unsigned")

df2.to_hdf(
    path_or_buf=OPTIMIZED_DATASET_PATH,
    key="df2",
    mode="w",
    format="table"
)