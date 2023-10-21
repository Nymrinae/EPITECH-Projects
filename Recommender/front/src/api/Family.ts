import { makeGetRequest } from './makeRequest'

class FamilyAPI {
  async getFamilies() {
    return makeGetRequest('/families')
  }

  async getFamiliesTotalSales() {
    return makeGetRequest('/families/sales')
  }

  async getFamiliesMonthSales(month: number) {
    return makeGetRequest(`/families/monthly-sales/${month}`)
  }
}

const familyAPI = new FamilyAPI()

export default familyAPI