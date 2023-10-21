import { get, post } from './request'

class MoviesAPI {
  getMovieById = async (id: string) => get(`/movies/${id}`)

  getMovieAPIData = async (id: string) => get(`/${id}`, { useImdbInstance: true })

  getMovies = async (page: string | number = 1, search: string = '') => get(`/movies?page=${page}&search=${search}`)

  getMoviesData = async () => get(`/movies/details`)

  getMovieDataByGenre = async (genre: string) => get(`/movies/details?genre=${genre}`)

  uploadPoster = async (file: FormData) => post('/movies/upload', file)
}

const moviesAPI = new MoviesAPI()

export default moviesAPI