<template>
  <StatHorizontalCard
    v-if="stat"
    :stat="stat"
  />
</template>

<script lang="ts">
import { Client } from '@/api'
import { Component, Prop, Vue } from 'vue-property-decorator'

@Component({
  components: {
    StatHorizontalCard: () => import('@/components/Cards/StatHorizontalCard.vue')
  }
})
export default class ClientClustering extends Vue {
  stat: any = null

  async mounted() {
    try {
      const { segment } = await Client.getClientSegment(this.$route.params.id)

      this.stat = {
        title: 'Client Cluster',
        value: segment
      }
    } catch (e) {
      console.error('Cannot get client cluster', e)
    }
  }
}
</script>