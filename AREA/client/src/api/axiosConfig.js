import axios from 'axios'

const server = process.env.SERV_ADDR || 'localhost'
const port = process.env.SERV_PORT || '8080'

const axiosInstance = axios.create({
  baseURL: `http://${server}:${port}`
})

export default axiosInstance
