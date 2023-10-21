from datasets import Dataset

import json
import pandas as pd


class Families(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def get_family_stats(self, family_filter: str):
        """
        Returns descriptive statistics for dataset containing only sales of a specific family
        """
        family_df = self.df[self.df['FAMILLE'] == family_filter]
        product_fields = [
            'FAMILLE',
            'UNIVERS',
            'MAILLE',
            'LIBELLE'
        ]

        stats = {
            'total_sales_count': len(family_df.index),
            'total_sales_value': family_df['PRIX_NET'].sum(),
            'num_products': len(family_df[product_fields].drop_duplicates().index),
            'mean_product_price': family_df['PRIX_NET'].mean(),
            'std_product_price': family_df['PRIX_NET'].std(),
            'min_product_price': family_df['PRIX_NET'].min(),
            'max_product_price': family_df['PRIX_NET'].max()
        }

        return json.loads(
            pd.Series(stats, index=stats.keys()).to_json()
        )

    def list(self):
        """
        Return a list of all the families in the dataset
        """
        return json.loads(
            self.df['FAMILLE'].drop_duplicates().to_json(orient='values')
        )

    def get_sales(self):
        """
        Return record of sales quantities for each family over the year
        """
        family_counts = (self
                         .df
                         .groupby(['FAMILLE'])
                         .size()
                         .sort_values(ascending=False))

        return [
            {'family': idx, 'count': count}
            for idx, count in family_counts.items()
        ]

    def get_monthly_sales(self, month: int):
        """
        Return record of sales quantities for each family for a given month
        """
        family_counts = (self
                         .df[self.df['MOIS_VENTE'] == month]
                         .groupby(['FAMILLE'])
                         .size()
                         .sort_values(ascending=False))

        return [
            {'family': idx, 'count': count}
            for idx, count in family_counts.items()
        ]
