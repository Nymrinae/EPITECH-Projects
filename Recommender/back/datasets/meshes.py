from datasets import Dataset

import json
import pandas as pd


class Meshes(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def list(self):
        """
        Return a list of all the meshes in the dataset
        """
        return json.loads(
            self.df['MAILLE'].drop_duplicates().to_json(orient='values')
        )

    def get_mesh_stats(self, mesh_filter: str):
        """
        Returns descriptive statistics for dataset containing only sales of a specific mesh
        """
        mesh_df = self.df[self.df['MAILLE'] == mesh_filter]
        product_fields = [
            'FAMILLE',
            'UNIVERS',
            'MAILLE',
            'LIBELLE'
        ]

        stats = {
            'total_sales_count': len(mesh_df.index),
            'total_sales_value': mesh_df['PRIX_NET'].sum(),
            'num_products': len(mesh_df[product_fields].drop_duplicates().index),
            'mean_product_price': mesh_df['PRIX_NET'].mean(),
            'std_product_price': mesh_df['PRIX_NET'].std(),
            'min_product_price': mesh_df['PRIX_NET'].min(),
            'max_product_price': mesh_df['PRIX_NET'].max()
        }

        return json.loads(
            pd.Series(stats, index=stats.keys()).to_json()
        )

    def get_sales(self):
        """
        Return record of sales quantities for each family over the year
        """
        mesh_counts = (self
                       .df
                       .groupby(['MAILLE'])
                       .size()
                       .sort_values(ascending=False))

        return [
            {'mesh': idx, 'count': count}
            for idx, count in mesh_counts.items()
        ]

    def get_monthly_sales(self, month: int):
        """
        Return record of sales quantities for each mesh for a given month
        """
        mesh_counts = (self
                       .df[self.df['MOIS_VENTE'] == month]
                       .groupby(['MAILLE'])
                       .size()
                       .sort_values(ascending=False))

        return [
            {'mesh': idx, 'count': count}
            for idx, count in mesh_counts.items()
        ]
