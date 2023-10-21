from datasets import Dataset

import numpy as np
import simplejson as json


class Client(Dataset):
    def __init__(self, df, client_id):
        super().__init__(df)
        self.client_id = client_id

    @property
    def client_id(self):
        return self._client_id

    @client_id.setter
    def client_id(self, client_id: int):
        if client_id not in self.df['CLI_ID'].values:
            raise ValueError()

        self._client_id = client_id

    def get_client_stats(self):
        """
        Returns descriptive statistics for a client's purchase history
        """
        stats = {
            'total_ticket_count': self.df['TICKET_ID'].nunique(),
            'total_ticket_value': self.df['PRIX_NET'].sum().item()
        }

        month_agg = (self.df
                     .groupby('MOIS_VENTE')
                     .agg({
                         'PRIX_NET': np.sum,
                         'TICKET_ID': lambda x: x.nunique()}))
        month_agg.columns = ['TOTAL_SPENT', 'NUM_TICKETS']

        ticket_agg = (self.df
                      .groupby('TICKET_ID')
                      .agg({
                          'PRIX_NET': np.sum,
                          'LIBELLE': lambda x: x.count()}))
        ticket_agg.columns = ['TOTAL_SPENT', 'NUM_PRODUCTS']

        stats.update({
            'min_monthly_spend': month_agg['TOTAL_SPENT'].min().item(),
            'max_monthly_spend': month_agg['TOTAL_SPENT'].max().item(),
            'mean_monthly_spend': month_agg['TOTAL_SPENT'].mean().item(),
            'std_monthly_spend': month_agg['TOTAL_SPENT'].std().item(),
            'min_monthly_visit': month_agg['NUM_TICKETS'].min().item(),
            'max_monthly_visit': month_agg['NUM_TICKETS'].max().item(),
            'mean_monthly_visit': month_agg['NUM_TICKETS'].mean().item(),
            'std_monthly_visit': month_agg['NUM_TICKETS'].std().item(),
            'min_ticket_value': ticket_agg['TOTAL_SPENT'].min().item(),
            'max_ticket_value': ticket_agg['TOTAL_SPENT'].max().item(),
            'mean_ticket_value': ticket_agg['TOTAL_SPENT'].mean().item(),
            'std_ticket_value': ticket_agg['TOTAL_SPENT'].std().item(),
            'min_ticket_qty': ticket_agg['NUM_PRODUCTS'].min().item(),
            'max_ticket_qty': ticket_agg['NUM_PRODUCTS'].max().item(),
            'mean_ticket_qty': ticket_agg['NUM_PRODUCTS'].mean().item(),
            'std_ticket_qty': ticket_agg['NUM_PRODUCTS'].std().item()
        })

        return json.loads(json.dumps(stats, ignore_nan=True))

    def get_top_products(self):
        product_counts = (self
                          .df[['FAMILLE', 'UNIVERS', 'MAILLE', 'LIBELLE']]
                          .value_counts())
        products = product_counts.keys().tolist()
        counts = product_counts.tolist()

        top_products = []
        for p_value, c_value in zip(products, counts):
            family, universe, mesh, label = p_value
            top_products.append({
                'product': {
                    'family': family,
                    'universe': universe,
                    'mesh': mesh,
                    'label': label
                },
                'count': c_value
            })

        return top_products
