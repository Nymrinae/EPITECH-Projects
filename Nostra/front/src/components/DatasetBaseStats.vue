<script lang="ts" setup>
import { Dataset } from '@/api'

const data = reactive({
  datasetStats: null as any
})

const shortestMovie = computed(() => {
  return data.datasetStats.shortest_movie
})

const longestMovie = computed(() => {
  return data.datasetStats.longest_movie
})

const totalMovies = computed(() => {
  return data.datasetStats.total_movies
})

const padTo2Digits = (num: number) => {
  return num.toString().padStart(2, '0');
}

const parseDateFromMinutes = (min: number) => {
  const minutes =  min % 60
  const hours = Math.floor(min / 60)

  return `${padTo2Digits(hours)}h${padTo2Digits(minutes)}`
}

const init = async() => {
  data.datasetStats = await Dataset.getDatasetStats()
}

init()
</script>

<template>
  <section v-if="data.datasetStats" class="text-gray-400 bg-gray-900 body-font">
    <div class="container px-5 pt-12 pb-6 mx-auto">
      <div class="flex flex-col text-center w-full mb-4">
        <h1 class="sm:text-3xl text-2xl font-medium title-font mb-4 text-white">
          Dataset Analysis
        </h1>
      </div>
      <div class="flex gap-2 text-center">
        <StatCard>
          <template #title>{{ totalMovies }}</template>
          <template #description> movies </template>
        </StatCard>
        <StatCard>
          <template #title>{{ shortestMovie.title }}</template>
          <template #description>
            Shortest movie - {{ parseDateFromMinutes(shortestMovie.duration) }}
          </template>
        </StatCard>
        <StatCard>
          <template #title>{{ longestMovie.title }}</template>
          <template #description>
            Longest movie - {{ parseDateFromMinutes(longestMovie.duration) }}
          </template>
        </StatCard>
      </div>
    </div>
  </section>
</template>