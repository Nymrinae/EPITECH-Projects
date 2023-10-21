import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns

DATASET_PATH = '../data/raw/KaDo.csv'
PRODUCT_DATASET_PATH = '../data/raw/Products_Full.csv'
CLIENT_DATASET_PATH = '../data/raw/Lines.csv'

pd.set_option('max_columns', None)
LINE_COLUMNS = [
    'TICKET_ID',
    'PRODUCT_ID',
    'PRIX_NET'
]


def main():
    df = pd.read_csv(DATASET_PATH)
    ticket_summary_df = (df
                         .groupby('TICKET_ID')
                         .agg({
                            'CLI_ID': lambda x: x.iloc[0],
                            'MOIS_VENTE': lambda x: x.iloc[0],
                            'PRIX_NET': np.sum,
                            'LIBELLE': lambda x: x.count()}))

    ticket_summary_df.columns = ['CLI_ID', 'MONTH', 'TOTAL', 'NUM_PRODUCTS']
    ticket_summary_df.to_hdf('../data/processed/TicketSummary.h5', 'ticket_summary', index=True)
    # df_product = pd.read_csv(PRODUCT_DATASET_PATH)
    #
    # df['PRODUCT_ID'] = np.nan
    # for index, row in df_product.iterrows():
    #     df.loc[
    #         (df['FAMILLE'] == row['FAMILLE']) &
    #         (df['UNIVERS'] == row['UNIVERS']) &
    #         (df['MAILLE'] == row['MAILLE']) &
    #         (df['LIBELLE'] == row['LIBELLE']),
    #         'PRODUCT_ID'
    #     ] = row['PRODUCT_ID']
    #
    #     print(index)

        # print(pd.isnull(row['PRODUCT_ID']))
        # if pd.isnull(row['PRODUCT_ID']):
        #     product = df_product.loc[
        #         (df_product['FAMILLE'] == row['FAMILLE']) &
        #         (df_product['UNIVERS'] == row['UNIVERS']) &
        #         (df_product['MAILLE'] == row['MAILLE']) &
        #         (df_product['LIBELLE'] == row['LIBELLE'])
        #     ]
        #
        #     # print(product)
        #
        #     df.loc[
        #         (df['FAMILLE'] == row['FAMILLE']) &
        #         (df['UNIVERS'] == row['UNIVERS']) &
        #         (df['MAILLE'] == row['MAILLE']) &
        #         (df['LIBELLE'] == row['LIBELLE'])
        #     ]['PRODUCT_ID'] = product['PRODUCT_ID']



    # # print(df.describe())
    # sns.countplot(x='MOIS_VENTE', data=df)
    # plt.title('Distribution of Gender   ')
    # plt.show()
    #
    # sns.countplot(x='FAMILLE', data=df)
    # plt.title('Distribution of Marital Status')
    # plt.xticks(rotation=90)
    # plt.tight_layout()
    # plt.show()
    #
    # # print(df)
    # df_product = df[PRODUCT_COLUMNS].drop_duplicates()
    # # This dataframe still contains duplicates
    # df_product = df_product.groupby([
    #     'FAMILLE',
    #     'UNIVERS',
    #     'MAILLE',
    #     'LIBELLE'
    # ])
    # print(df['PRODUCT_ID'].isnull().values.any())
    # clients = df[LINE_COLUMNS]
    # clients.to_csv(CLIENT_DATASET_PATH, index=False)
    # print(clients.count())

    # print(num_clients)

    # print(df_product.describe())


if __name__ == '__main__':
    main()
