<template>
  <Loading v-if="tabLoading" />
  <div v-else>
    <b-row>
      <b-col cols="12" md="6">
        <StatTopCard :products="top10Data" />
      </b-col>
      <b-col cols="12" md="6">
        <TopProduct :product="top10Data[0]" />
        <BarChartHorizontal
          :title="`Top 10  products sold on ${currentMonth.value ? currentMonth.title : 'January'}`"
          :categories="categories"
          :data="data"
        />
      </b-col>
    </b-row>
  </div>
</template>

<script lang="ts">
import { Product } from '@/api'
import { GraphModule } from '@/store/modules'
import { Component, Vue, Watch } from 'vue-property-decorator'

@Component({
  components: {
    BarChartHorizontal: () => import('@/components/Charts/BarChartHorizontal.vue'),
    StatTopCard: () => import('@/components/Cards/StatTopCard.vue'),
    TopProduct: () => import('@/components/Cards/TopProduct.vue')
  }
})
export default class DatasetProductsTab extends Vue {
  @GraphModule.State currentMonth
  @GraphModule.State currentEntry
  data: any[] = []
  top10Data: any[] = []
  categories: any[] = []

  @Watch('currentMonth')
  @Watch('currentEntry')
  async onGraphSettingsChange() {
    await this.getProductMonthlySales()
  }

  async mounted() {
    await this.getProductMonthlySales()
    await this.getAllTimeTopProducts()
    // @ts-ignore
    this.updateTabLoadingState(false)
  }

  async getAllTimeTopProducts() {
    try {
      const top10Data = await Product.getTopProducts()

      this.top10Data = top10Data
    } catch(e) {
      console.error('Cannot fetch top 10 all time product data', e)
    }
  }

  async getProductMonthlySales() {
    try {
      // default to January
      const currentMonthValue = this.currentMonth.value ?? 1
      const currentEntryValue = this.currentEntry.value > 0 ? this.currentEntry.value : false
      const productMonthlyData = await Product.getProductsMonthSales(currentMonthValue)
      const slicedStatsData = currentEntryValue ? productMonthlyData.slice(0, currentEntryValue) : productMonthlyData

      this.categories = slicedStatsData.map((e: any) => e.product.label)
      this.data = [{
        data: slicedStatsData.map((e: any) => e.count)
      }]
    } catch (e) {
      console.error('Cannot fetch Product data', e)
    }
  }
}
</script>