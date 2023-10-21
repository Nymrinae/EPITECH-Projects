from datasets import Dataset

import json


class Products(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def list(self):
        """
        Return a list of all the products in the dataset
        """
        product_fields = [
            'LIBELLE',
            'FAMILLE',
            'UNIVERS',
            'MAILLE'
        ]
        return json.loads(
            self.df[product_fields].drop_duplicates().to_json(orient='records')
        )

    def top_products(self):
        """
        Returns a list of top sold products for the year
        """
        product_counts = (self
                          .df['LIBELLE']
                          .value_counts()
                          .head(10))

        top_products = []
        for idx, value in product_counts.items():
            line = self.df[self.df['LIBELLE'] == idx].iloc[0]

            top_products.append({
                'product': {
                    'family': line['FAMILLE'],
                    'universe': line['UNIVERS'],
                    'mesh': line['MAILLE'],
                    'label': idx
                },
                'count': value
            })

        return top_products

    def top_monthly_products(self, month: int):
        """
        Returns a list of top sold products for a given month
        """
        product_counts = (self
                          .df[self.df['MOIS_VENTE'] == month]['LIBELLE']
                          .value_counts()
                          .head(10))

        top_products = []
        for idx, value in product_counts.items():
            line = self.df[self.df['LIBELLE'] == idx].iloc[0]

            top_products.append({
                'product': {
                    'family': line['FAMILLE'],
                    'universe': line['UNIVERS'],
                    'mesh': line['MAILLE'],
                    'label': idx
                },
                'count': value
            })

        return top_products
