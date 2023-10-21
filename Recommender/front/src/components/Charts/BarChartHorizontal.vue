<template>
  <b-card no-body>
    <b-card-header>
      <div>
        <b-card-title class="font-weight-bolder">
          {{ title }}
        </b-card-title>
      </div>
    </b-card-header>

    <b-card-body>
      <VueApexCharts
        type="bar"
        height="350"
        :options="chartOptions"
        :series="data"
      />
    </b-card-body>
  </b-card>
</template>

<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator'
import VueApexCharts from 'vue-apexcharts'

@Component({
  components: {
    VueApexCharts
  }
})
export default class BarChartHorizontal extends Vue {
  @Prop() title
  @Prop() categories
  @Prop() data

  get chartOptions() {
    return {
      chart: {
        toolbar: {
          show: false,
        },
      },
      plotOptions: {
        bar: {
          horizontal: true,
          barHeight: '30%',
          endingShape: 'rounded',
        },
      },
      grid: {
        xaxis: {
          lines: {
            show: false,
          }
        }
      },
      dataLabels: {
        enabled: false,
      },
      xaxis: {
        categories: this.categories
      }
    }
  }
}
</script>