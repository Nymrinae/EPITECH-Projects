import { get, post } from './request'

class RankingAPI {
  getTopCountries = async () => get(`/ranking/top-countries`)

  getTopDate = async () => get(`/ranking/top-date`)
}

const rankingAPI = new RankingAPI()

export default rankingAPI