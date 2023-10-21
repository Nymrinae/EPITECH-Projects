import { makeGetRequest } from './makeRequest'

class MeshAPI {
  async getMeshes() {
    return makeGetRequest('/meshes')
  }

  async getMeshesTotalSales() {
    return makeGetRequest('/meshes/sales')
  }

  async getMeshesMonthSales(month: number) {
    return makeGetRequest(`/meshes/monthly-sales/${month}`)
  }
}

const meshAPI = new MeshAPI()

export default meshAPI