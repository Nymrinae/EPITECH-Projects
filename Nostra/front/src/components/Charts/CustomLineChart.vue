<script lang="ts" setup>
import { LineChart } from 'vue-chart-3'

const props = defineProps({
  title: {
    type: String,
    required: true,
    default :'',
  },
  chartData: {
    type: Object,
    required: true,
    default: {},
  },
  selectedGenre: {
    type: String,
    required: true,
    default: {}
  }
})

const lineRef = ref(null)
const chartData = computed(() => ({
  labels: props.chartData.map(e => e.year),
  datasets: [
    {
      data: props.chartData.map(e => e.value),
      backgroundColor: ['#77CEFF', '#0079AF', '#123E6B', '#97B0C4', '#A5C8ED'],
    },
  ],
}))
const options = computed(() => ({
  responsive: true,
  plugins: {
    legend: {
      display: false,
    },
    title: {
      display: true,
      text: props.title,
    },
  },
}))
</script>

<template>
  <LineChart
    ref="lineRef"
    :chartData="chartData"
    :options="options"
  />
</template>