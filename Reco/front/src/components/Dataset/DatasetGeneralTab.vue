<template>
  <Loading v-if="tabLoading" />
  <div v-else>
    <b-row>
      <b-col
        v-for="stat in stats"
        :key="stat.title"
      >
        <StatHorizontalCard :stat="stat" />
      </b-col>
    </b-row>
    <b-row>
      <b-col cols="12">
        <BarChartHorizontal
          title="Amount of products sold based on months"
          :categories="months"
          :data="data"
        />
      </b-col>
    </b-row>
  </div>
</template>

<script lang="ts">
import { Dataset } from '@/api'
import { Component, Vue } from 'vue-property-decorator'

@Component({
  components: {
    BarChartHorizontal: () => import('@/components/Charts/BarChartHorizontal.vue'),
    StatHorizontalCard: () => import('@/components/Cards/StatHorizontalCard.vue')
  }
})
export default class DatasetGeneralTab extends Vue {
  stats = []
  months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
  data: any[] = []

  async mounted() {
    try {
      this.stats = await Dataset.getDatasetStats()

      const monthlyAmountData = await Dataset.getDatasetMonthlyAmount()

      this.data = [{
        data: monthlyAmountData.map((e: any) => e.count)
      }]
      // @ts-ignore
      this.updateTabLoadingState(false)
    } catch (e) {
      console.error('Cannot fetch dataset general stats', e)
    }
  }
}
</script>