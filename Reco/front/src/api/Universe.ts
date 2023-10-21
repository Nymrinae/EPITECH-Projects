import { makeGetRequest } from './makeRequest'

class UniverseAPI {
  async getUniverses() {
    return makeGetRequest('/universes')
  }

  async getUniversesTotalSales() {
    return makeGetRequest('/universes/sales')
  }

  async getUniverseMonthSales(month: number) {
    return makeGetRequest(`/universes/monthly-sales/${month}`)
  }
}

const universeAPI = new UniverseAPI()

export default universeAPI