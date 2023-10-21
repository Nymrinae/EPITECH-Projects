import axios from 'axios'

const axiosInstance = axios.create({
  baseURL: 'http://localhost:5000'
})

const imdbInstance = axios.create({
  baseURL: 'http://api.themoviedb.org/3/movie',
  headers: {
    'Authorization': 'Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI5OWJlODYyNDgyNWVlMGFkZDU0ZThiNGJlYjY4M2E1OCIsInN1YiI6IjYyNTlhYTUyM2FjZDIwMTYyOTFkODhlNSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.WaCgAa4LEFFgAf5HFAYK3mh_PnAXBWfvl-KhFfUxmiE'
  }
})

export {
  axiosInstance,
  imdbInstance
}