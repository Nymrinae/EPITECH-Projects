import { makeGetRequest } from './makeRequest'

class ClientAPI {
  async checkClient(clientId: string) {
    return makeGetRequest(`/clients/${clientId}/check`)
  }

  async getClientStats(clientId: string) {
    return makeGetRequest(`/clients/${clientId}/stats`)
  }

  async getClientTickets(clientId: string) {
    return makeGetRequest(`/clients/${clientId}/tickets`)
  }

  async getClientSegment(clientId: string) {
    return makeGetRequest(`/clients/${clientId}/segment`)
  }
}

const clientAPI = new ClientAPI()

export default clientAPI