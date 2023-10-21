<script setup lang="ts">
import { Ref } from 'vue'
import { Movies } from '@/api'

const route = useRoute()
const movie: Ref<Movie> = ref({} as Movie)
const movieImg = ref('')

const init = async() => {
  try {
    movie.value = (await Movies.getMovieById(route.params.id as string))[0]
    const data = await Movies.getMovieAPIData(route.params.id as string)

    movieImg.value = `https://image.tmdb.org/t/p/original${data?.poster_path}` || ''
  } catch(e) {
    console.error(`Cannot fetch data for image id ${route.params.id}`, e)
  }
}

init()
</script>

<template>
  <LayoutDefault>
    <section class="h-full text-gray-400 bg-gray-900 body-font">
      <div  v-if="movie && movieImg"  class="container mx-auto flex px-5 py-12 md:flex-row flex-col">
        <div class="lg:max-w-lg lg:w-full md:w-1/2 md:w-5/6 md:mb-0 mb-10">
          <img
            :src="movieImg"
            alt="movie-image"
            class="object-cover object-center rounded text-center"
          />
        </div>
        <div class="lg:flex-grow md:w-1/2 pl-8 flex flex-col md:items-start md:text-left text-center">
          <h1 class="title-font sm:text-4xl text-3xl mb-4 font-medium text-white">{{ movie.title }} ({{ movie.year }}) </h1>
          <p class="mb-4">
            <span class="font-bold"> 🌟 {{ movie.avg_vote }}</span>
            | {{ movie.duration }}min
            | {{ movie.genre }}
          </p>
          <p class="mb-8 leading-relaxed text-justify">{{ movie.description }}</p>
          <!-- <p
            v-for="key in Object.keys(Object.entries(movie).reduce((a, [k, v]) => (k === 'description' || v == null ? a : (a[k] = v, a)), {}))"
            :key="key"
            class="pb-4"
          > -->
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Director </span> <br />
            <span> {{ movie.director }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Writers </span> <br />
            <span> {{ movie.writer }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Actors </span> <br />
            <span> {{ movie.actors }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Production company </span> <br />
            <span> {{ movie.production_company }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Language </span> <br />
            <span> {{ movie.language }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Country </span> <br />
            <span> {{ movie.country }}</span>
          </p>
          <p class="pb-4">
            <span class="mr-4 font-bold text-white"> Budget </span> <br />
            <span> {{ movie.budget || 'N/A' }}</span>
          </p>
          <p class="border border-gray-600 w-full mb-4" />
          <p> {{ movie.metascore || 'N/A' }} <span class="font-bold">Metascore </span> </p>
          <div class="table lg:inline-flex">
            <div class="pr-4">
              <span class="font-bold">Votes: {{ movie.vote || 'N/A' }}</span>
            </div>
            <span class="hidden md:block"> | </span>
            <div class="px-4">
              <span class="font-bold">{{ movie.reviews_from_critics }}</span> reviews from critics
            </div>
            <span class="hidden md:block"> | </span>
            <div class="px-4">
              <span class="font-bold">{{ movie.reviews_from_users }}</span> reviews from users
            </div>
          </div>
        </div>
      </div>
    </section>
  </LayoutDefault>
</template>

<style>
</style>