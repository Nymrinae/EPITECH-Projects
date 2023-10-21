<template>
  <Loading v-if="tabLoading" />
  <div v-else>
    <BarChartHorizontal
      :title="title"
      :categories="categories"
      :data="data"
    />
  </div>
</template>

<script lang="ts">
import { Family, Mesh, Universe } from '@/api'
import { DatasetCategoryType } from '@/types/enums'
import { Component, Prop, Vue, Watch } from 'vue-property-decorator'
import { GraphModule } from '@/store/modules'

@Component({
  components: {
    BarChartHorizontal: () => import('@/components/Charts/BarChartHorizontal.vue')
  }
})
export default class DatasetCategoryTab extends Vue {
  @GraphModule.State currentMonth
  @GraphModule.State currentEntry

  @Prop({ required: true }) type!: DatasetCategoryType
  DatasetCategoryType = DatasetCategoryType

  categories: any[] = []
  data: any[] = []

  get title() {
    return `Amount of products with ${this.type} type sold ${this.currentMonth.value ? `on ${this.currentMonth.title}` :'throughout the year' }`
  }

  @Watch('currentMonth')
  @Watch('currentEntry')
  async onGraphSettingsChange() {
    await this.getProductTypeItemsSoldStats()
  }

  async mounted() {
    await this.getProductTypeItemsSoldStats()
  }

  async getProductTypeItemsSoldStats() {
    try {
      let statsData = []
      const currentMonthValue = this.currentMonth.value ?? null
      const currentEntryValue = this.currentEntry.value > 0 ? this.currentEntry.value : false

      switch (this.type) {
        case DatasetCategoryType.FAMILIES:
          statsData = currentMonthValue
            ? await Family.getFamiliesMonthSales(currentMonthValue)
            : await Family.getFamiliesTotalSales()
          break;
        case DatasetCategoryType.UNIVERSES:
          statsData = currentMonthValue 
            ? await Universe.getUniverseMonthSales(currentMonthValue)
            : await Universe.getUniversesTotalSales()
          break;
        case DatasetCategoryType.MESHES:
          statsData = currentMonthValue
           ? await Mesh.getMeshesMonthSales(currentMonthValue)
           : await Mesh.getMeshesTotalSales()
          break;
      }

      const slicedStatsData = currentEntryValue ? statsData.slice(0, currentEntryValue) : statsData

      this.categories = slicedStatsData.map((e: any) => e[this.type.toLowerCase()])
      this.data = [{
        data: slicedStatsData.map((e: any) => e.count)
      }]
      // @ts-ignore
      this.updateTabLoadingState(false)
    } catch (e) {
      console.error('')
    }
  }
}
</script>