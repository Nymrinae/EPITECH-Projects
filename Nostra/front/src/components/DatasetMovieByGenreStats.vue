<script lang="ts" setup>
import { Dataset, Movies, Ranking } from '@/api'
import { Chart, registerables } from "chart.js";

Chart.register(...registerables);

const data = reactive({
  datasetStats: null as any,
  selectedGenre: null as any,
  selectedGenreData: {} as any,
  moviesBasedOnYear: [] as any,
  moviesBasedOnCountry: [] as any,
})

const moviesGenres = computed(() => {
  return data.datasetStats.movies_genres.sort()
})

const generateTitle = (basedOn): string => {
  return data.selectedGenre
    ? `Top 10 ${data.selectedGenre} movies based on ${basedOn}`
    : `Top 10 based on ${basedOn}`
}

const setSelectedGenre = (genre) => {
  data.selectedGenre = data.selectedGenre === genre ? null : genre
}

const setGenreData = async (newGenre) => {
  data.selectedGenreData = await Movies.getMovieDataByGenre(newGenre)
  data.moviesBasedOnYear = formatData(data.selectedGenreData.movies_based_on_year_by_genre)
  data.moviesBasedOnCountry = formatData(data.selectedGenreData.movies_based_on_country_by_genre)
}

const setNoGenreData = async () => {
  const { movies_based_on_year, movies_based_on_country } = await Movies.getMoviesData()

  data.moviesBasedOnYear = formatData(movies_based_on_year, { slice: false })
  data.moviesBasedOnCountry = formatData(movies_based_on_country, { slice: false })
}

const formatData = (data, { slice } = { slice: true }) => {
  const formattedData = Object.entries(data)
    .sort((a: any, b: any) => b[1] - a[1])
    .map((e: any) => {
      const [year, value] = e

      return { year, value }
    })

  return slice ? formattedData.slice(0, 10) : formattedData.reverse()
}

watch(
  () => data.selectedGenre, async (newGenre) => {
    newGenre ? await setGenreData(newGenre) : await setNoGenreData()
  },
  {
    deep: true,
    immediate: true
  },
)

const init = async() => {
  data.datasetStats = await Dataset.getDatasetStats()
  await setNoGenreData()
}

init()
</script>

<template>
  <section v-if="data.datasetStats" class="text-gray-400 bg-gray-900 body-font">
    <div class="container px-5 pb-12 mx-auto">
      <div class="text-center my-4">
        <span
          v-for="movieGenre in moviesGenres"
          class="inline-flex m-2 items-center px-3 py-0.5 rounded-full text-sm font-medium bg-gray-100 text-gray-800 cursor-pointer"
          :class="{ 'border border-red-200 bg-red-200': data.selectedGenre === movieGenre }"
          @click="setSelectedGenre(movieGenre)"
        >
          {{ movieGenre }}
        </span>
      </div>
      <div v-if="!data.selectedGenre" class="text-center mt-4 italic">
        Select a genre by clicking on a tag
      </div>
      <div v-else-if="data.moviesBasedOnYear.length > 0" class="flex gap-2 text-center">
        <StatCard>
          <template #title>{{ data.selectedGenreData.movies_with_genre_only }} movies </template>
          <template #description>Films with {{ data.selectedGenre }} genre only </template>
        </StatCard>
        <StatCard>
          <template #title>{{ data.selectedGenreData.movies_with_at_least_genre }} movies </template>
          <template #description>Films with at least {{ data.selectedGenre }} genre</template>
        </StatCard>
        <StatCard>
          <template #title>{{ data.moviesBasedOnYear[0].value }} movies on {{ data.moviesBasedOnYear[0].year }}</template>
          <template #description>Most published on</template>
        </StatCard>
      </div>
      <div
        v-if="data.selectedGenre && data.moviesBasedOnYear.length > 0"
        class="flex mt-8 justify-evenly"
      >
        <CustomBarChart
          ref="barRef"
          :title="generateTitle('year')"
          :chartData="data.moviesBasedOnYear"
          :selected-genre="data.selectedGenre"
        />
        <CustomBarChart
          ref="barRef"
          :title="generateTitle('country')"
          :chartData="data.moviesBasedOnCountry"
          :selected-genre="data.selectedGenre"
        />
      </div>
      <div
        v-else
        class="flex mt-8 justify-evenly"
      >
        <CustomLineChart
          ref="lineRef"
          title="Movies based on year"
          :chartData="data.moviesBasedOnYear"
          :selected-genre="data.selectedGenre"
          :width="1200"
        />
      </div>
    </div>
  </section>
</template>