from datasets import Client, Dataset


class TicketDetails(Dataset):
    def __init__(self, df):
        super().__init__(df)

    def get_ticket_details(self, ticket_id: int):
        """
        Returns details of given ticket
        """
        ticket_df = self.df[self.df['TICKET_ID'] == ticket_id]

        ticket_details = {
            'ticket_id': ticket_id,
            'month': int(ticket_df['MOIS_VENTE'].iloc[0]),
            'total_value': ticket_df['PRIX_NET'].sum().item(),
            'products': [
                {
                    'family': value['FAMILLE'],
                    'universe': value['UNIVERS'],
                    'mesh': value['MAILLE'],
                    'label': value['LIBELLE'],
                    'price': value['PRIX_NET'],
                } for idx, value in ticket_df.iterrows()
            ]
        }
        print(ticket_details)

        return ticket_details
