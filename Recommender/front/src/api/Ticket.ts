import { makeGetRequest } from './makeRequest'

class TicketAPI {
  async getTicketInfo(ticketId: string) {
    return makeGetRequest(`/tickets/${ticketId}/info`)
  }

  async getTicketsStats() {
    return makeGetRequest('/tickets/stats')
  }

  async getMonthlyClientCountTickets() {
    return makeGetRequest('/tickets/clients/monthly-counts')
  }
}

const ticketAPI = new TicketAPI()

export default ticketAPI