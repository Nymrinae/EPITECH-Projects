from datasets import Client, Dataset

import json
import pandas as pd


class Tickets(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def get_ticket_count(self):
        """
        Return the the number of tickets in the dataset
        """
        return self.df['TICKET_ID'].unique().count()

    def get_ticket_stats(self):
        """
        Returns descriptive statistics for tickets dataset
        """
        stats = [
            {'title': 'Total tickets', 'value': len(self.df.index) },
            {'title': 'Total tickets value', 'value': int(self.df['TOTAL'].sum()), 'currency': True},
            {'title': 'Minimum ticket value', 'value': int(self.df['TOTAL'].min()), 'currency': True},
            {'title': 'Maximum ticket value', 'value': int(self.df['TOTAL'].max()), 'currency': True},
            {'title': 'Average ticket value', 'value': int(self.df['TOTAL'].mean()), 'currency': True},
            {'title': 'Standard deviation ticket value', 'value': str(self.df['TOTAL'].std())},
            {'title': 'Minimum products on a ticket', 'value': str(self.df['NUM_PRODUCTS'].min())},
            {'title': 'Maximum products on a ticket', 'value': str(self.df['NUM_PRODUCTS'].max())},
            {'title': 'Average ticket quantity', 'value': str(self.df['NUM_PRODUCTS'].mean())},
            {'title': 'Standard deviation ticket quantity', 'value': str(self.df['NUM_PRODUCTS'].std())}
        ]

        return stats

    def get_monthly_client_counts(self):
        """
        Return the number of client tickets for each month
        """
        # month_tickets = self.df[['MOIS_VENTE', 'TICKET_ID']].drop_duplicates()
        month_groups = self.df.groupby('MONTH').size()

        ticket_counts = [
            {'month': str(idx), 'count': count}
            for idx, count in month_groups.items()
        ]

        return ticket_counts

    def get_monthly_distinct_client_counts(self):
        """
        Return the number of distinct clients for each month
        """
        month_tickets = self.df[['MONTH', 'CLI_ID']].drop_duplicates()
        month_groups = month_tickets.groupby('MONTH').size()

        ticket_counts = [
            {'month': str(idx), 'count': count}
            for idx, count in month_groups.items()
        ]

        return ticket_counts

    def get_monthly_returning_client_counts(self):
        """
        Return the number of clients that returned at least twice in a month for each month
        """
        month_tickets = self.df[['MONTH', 'CLI_ID']]
        # Keep only clients that are present more than once in a month
        month_tickets = (month_tickets[month_tickets.duplicated(keep=False)]
                         .drop_duplicates())
        month_groups = month_tickets.groupby('MONTH').size()

        ticket_counts = [
            {'month': str(idx), 'count': count}
            for idx, count in month_groups.items()
        ]

        return ticket_counts

    def get_client_tickets(self, client: Client):
        """
        Return all tickets for a given client (ticket_id, month)
        """
        ticket_groups = (self
                         .df[self.df['CLI_ID'] == client.client_id]
                         .groupby(['TICKET_ID', 'MOIS_VENTE']))

        tickets = [
            {'ticket_id': str(ticket_id), 'month': str(month)}
            for (ticket_id, month), group in ticket_groups
        ]

        return tickets

    def getAmountTicketsPerMonth(self):
        return self.df.groupby("MOIS_VENTE")["TICKET_ID"].count()

    def getAverageTicketsPerMonth(self):
        return self.df.groupby("MOIS_VENTE")["TICKET_ID"].mean()

    def getAmountOfTicketsFromClient(self, customerId):
        return len(self.df[self.df['CLI_ID'] == int(customerId)].groupby("TICKET_ID"))
