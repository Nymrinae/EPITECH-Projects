import { makeGetRequest } from './makeRequest'

class DatasetAPI {
  async getDatasetStats() {
    return makeGetRequest('/dataset/stats')
  }

  async getDatasetMonthlyAmount() {
    return makeGetRequest('/dataset/monthly-stats/amount')
  }
}

const datasetAPI = new DatasetAPI()

export default datasetAPI