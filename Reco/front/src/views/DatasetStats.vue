<template>
  <b-tabs v-model="tabIndex" content-class="mt-2" pills justified lazy>
    <b-tab v-for="tab in datasetCategoriesTabs"
      :key="tab.title"
      :title="tab.title"
      lazy
    >
      <component
        :is="tab.component"
        :type="tab.type"
      />
    </b-tab>
  </b-tabs>
</template>

<script lang="ts">
import { Component, Vue, Watch } from 'vue-property-decorator'
import { DatasetCategoryType } from '@/types/enums'
import { GraphModule } from '@/store/modules'

@Component
export default class DatasetStats extends Vue {
  @GraphModule.State tabLoading
  @GraphModule.Mutation updateTabLoadingState

  tabIndex = 0

  @Watch('tabIndex')
  onTabChange() {
    this.updateTabLoadingState(true)
  }

  datasetCategoriesTabs = [
    { title: 'General', component: () => import('@/components/Dataset/DatasetGeneralTab.vue') }, 
    { title: 'Families', type: DatasetCategoryType.FAMILIES, component: () => import('@/components/Dataset/DatasetCategoryTab.vue') },
    { title: 'Meshes', type: DatasetCategoryType.MESHES, component: () => import('@/components/Dataset/DatasetCategoryTab.vue') },
    { title: 'Universes', type: DatasetCategoryType.UNIVERSES, component: () => import('@/components/Dataset/DatasetCategoryTab.vue') },
    { title: 'Products', component: () => import('@/components/Dataset/DatasetProductsTab.vue') },
    { title: 'Tickets', component: () => import('@/components/Dataset/DatasetTicketsTab.vue') }
  ]
}
</script>