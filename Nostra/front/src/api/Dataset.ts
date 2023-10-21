import { get } from './request'

class DatasetAPI {
  getDatasetStats = async() => get('/dataset/stats')
}

const datasetAPI = new DatasetAPI()

export default datasetAPI