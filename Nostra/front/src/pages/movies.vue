<script setup lang="ts">
import { Movies } from '@/api'

const route = useRoute()
const router = useRouter()
const data = reactive({
  movies: null as any,
  page: Number(route.query.page),
  search: ''
})

const getMovies = async(page: number, search: string = '') => {
  const movies = await Movies.getMovies(page, search)
  
  return movies
}

watch(() => route.query.page, async(newPage) => {
    if (!newPage) return

    data.movies = await getMovies(Number(newPage), data.search)
  }, {
    deep: true,
    immediate: true
  }
)

const searchMovie = async() => {
  data.page = 1
  data.movies = await getMovies(data.page, data.search)

  router.replace({
    path: route.path,
    query: {
      page: data.page,
      search: data.search
    }
  })
}

const checkKey = async(e: KeyboardEvent) => {
  if (e.key === 'Enter')
    await searchMovie()
}

const init = async() => {
  data.movies = await getMovies(data.page, route.query.search as string)

  if (!data.page) {
    router.replace({
      path: route.path,
      query: { page: 1 }
    })
  }
}

init()
</script>

<template>
  <LayoutDefault>
    <section v-if="data.movies" class="h-full text-gray-400 bg-gray-900 body-font">
      <div class="container px-5 pt-12 pb-4 mx-auto">
        <div class="flex mb-4 justify-between">
          <div>
            <h1 class="sm:text-3xl text-2xl text-center font-medium title-font text-white">Movies included on the dataset</h1>
          </div>
          <div class="relative mb-4">
            <input
              v-model="data.search"
              type="text"
              id="name"
              name="name"
              placeholder="Search a movie by name"
              class="bg-gray-800 rounded border border-gray-700 focus:border-indigo-500 focus:ring-2 focus:ring-indigo-900 text-base outline-none text-gray-100 py-1 px-3 leading-8 transition-colors duration-200 ease-in-out"
              @keydown="checkKey"
            />
            <div
              class="absolute inset-y-0 right-0 pr-3 flex items-center cursor-pointer"
              @click="searchMovie"
            >
              <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
                <path stroke-linecap="round" stroke-linejoin="round" d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z" />
              </svg>
            </div>
          </div>
        </div>
        <div v-if="data?.movies.data" class="flex flex-wrap -m-2">
          <MovieCard
            v-for="movie in data.movies.data"
            :key="movie.imdb_title_id"
            :movie="movie"
            @click="router.push({
              name: 'movies-id',
              params: {
                id: movie.imdb_title_id
              }
            })"
          />
        </div>
      </div>
      <Pagination
        :min="data?.movies.min"
        :max="data?.movies.max"
        :results="data?.movies.results"
      />
    </section>
  </LayoutDefault>
</template>

<style>
</style>