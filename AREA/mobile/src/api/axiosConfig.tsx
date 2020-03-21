import axios from 'axios'

// const server = process.env.SERV_ADDR || 'localhost'
// const port = process.env.SERV_PORT || '8080'

// const axiosInstance = axios.create({
//   baseURL: `http://${server}:${port}`
// })

const axiosInstance = axios.create({
  // baseURL: 'http://192.168.1.39:8080'
  baseURL: 'http://0.0.0.0:8080'
})

export default axiosInstance