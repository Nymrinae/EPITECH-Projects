<template>
  <Loading v-if="tabLoading" />
  <div v-else>
    <b-row>
      <b-col
        v-for="stat in stats"
        :key="stat.title"
        cols="6"
        md="3"
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
import { Ticket } from '@/api'
import { Component, Vue } from 'vue-property-decorator'

@Component({
  components: {
    BarChartHorizontal: () => import('@/components/Charts/BarChartHorizontal.vue'),
    StatHorizontalCard: () => import('@/components/Cards/StatHorizontalCard.vue')
  }
})
export default class DatasetTicketsTab extends Vue {
  stats = []
  months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
  data: any[] = []

  async mounted() {
    try {
      this.stats = await Ticket.getTicketsStats()

      const monthlyClientCounts = await Ticket.getMonthlyClientCountTickets()

      this.data = [{
        data: monthlyClientCounts.map((e: any) => e.count)
      }]
      // @ts-ignore
      this.updateTabLoadingState(false)
    } catch (e) {
      console.error('Cannot fetch dataset general stats', e)
    }
  }
}
</script>