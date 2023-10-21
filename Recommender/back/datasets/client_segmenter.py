from datasets import Client, Dataset


class ClientSegmenter(Dataset):
    def __init__(self, df, pca, model):
        super().__init__(df)
        self.pca = pca
        self.model = model

    def get_client_segment(self, client: Client):
        client_df = self.df[self.df.index == client.client_id]
        client_reduced = self.pca.transform(client_df)
        segment = self.model.predict(client_reduced)
        return int(segment[0])
