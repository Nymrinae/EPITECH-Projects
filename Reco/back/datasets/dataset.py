import json

class Dataset:
    def __init__(self, df):
        self.df = df
    
    def get_clients_amount(self):
        """
        Return total amount of clients
        """
        return self.df['CLI_ID'].drop_duplicates().count()

    def get_products_amount(self):
        """
        Return total amount of products
        """
        return self.df["LIBELLE"].drop_duplicates().count()

    def get_products_sold_amount(self):
        """
        Return total amount of products sold
        """
        return self.df["LIBELLE"].value_counts().sum()

    def get_total_amount_spent(self):
        """
        Return the total of amount spent
        """
        return self.df["PRIX_NET"].sum()
    
    def get_amount_spent_by_month(self):
        """
        Return amount spent by month
        """
        amount_spent_by_month = self \
            .df[["PRIX_NET", "MOIS_VENTE"]] \
            .groupby("MOIS_VENTE")["PRIX_NET"] \
            .count()

        return [
            {'month': idx, 'count': count}
            for idx, count in amount_spent_by_month.items()
        ]
    
    def get_amount_spent_by_month_average(self):
        """
        Return amount spent by month on average
        """
        return self \
            .df[["PRIX_NET", "MOIS_VENTE"]] \
            .groupby("MOIS_VENTE")["PRIX_NET"] \
            .count() \
            .mean()
