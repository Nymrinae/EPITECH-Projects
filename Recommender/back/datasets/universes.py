from datasets import Dataset

import json
import pandas as pd


class Universes(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def list(self):
        """
        Return a list of all the universes in the dataset
        """
        return json.loads(
            self.df['UNIVERS'].drop_duplicates().to_json(orient='values')
        )

    def get_universe_stats(self, mesh_filter: str):
        """
        Returns descriptive statistics for dataset containing only sales of a specific universe
        """
        universe_df = self.df[self.df['UNIVERS'] == mesh_filter]
        product_fields = [
            'FAMILLE',
            'UNIVERS',
            'MAILLE',
            'LIBELLE'
        ]

        stats = {
            'total_sales_count': len(universe_df.index),
            'total_sales_value': universe_df['PRIX_NET'].sum(),
            'num_products': len(universe_df[product_fields].drop_duplicates().index),
            'mean_product_price': universe_df['PRIX_NET'].mean(),
            'std_product_price': universe_df['PRIX_NET'].std(),
            'min_product_price': universe_df['PRIX_NET'].min(),
            'max_product_price': universe_df['PRIX_NET'].max()
        }

        return json.loads(
            pd.Series(stats, index=stats.keys()).to_json()
        )

    def get_sales(self):
        """
        Return record of sales quantities for each family over the year
        """
        universe_counts = (self
                           .df
                           .groupby(['UNIVERS'])
                           .size()
                           .sort_values(ascending=False))

        return [
            {'universe': idx, 'count': count}
            for idx, count in universe_counts.items()
        ]

    def get_monthly_sales(self, month: int):
        """
        Return record of sales quantities for each universe for a given month
        """
        universe_counts = (self
                           .df[self.df['MOIS_VENTE'] == month]
                           .groupby(['UNIVERS'])
                           .size()
                           .sort_values(ascending=False))

        return [
            {'universe': idx, 'count': count}
            for idx, count in universe_counts.items()
        ]
