<template>
  <b-row>
    <b-col cols="12" md="6">
      <ClientStatsList
        title="General stats"
        :stats="stats.filter(e => !isSegmentation(e))"
      />
    </b-col>
    <b-col cols="12" md="6">
      <ClientStatsList
        title="Segmentation stats"
        :stats="stats.filter(isSegmentation)"
      />
    </b-col>
  </b-row>
</template>

<script lang="ts">
import { Client } from '@/api'
import { Component, Vue } from 'vue-property-decorator'

@Component({
  components: {
    ClientStatsList: () => import('./ClientStatsList.vue')
  }
})
export default class ClientGeneralStats extends Vue {
  stats: any[] = []

  isSegmentation(e) {
    return e.key.includes('mean') || e.key.includes('std')
  }

  async mounted() {
    const clientStats = await Client.getClientStats(this.$route.params.id)

    this.stats = Object.entries(clientStats).map(([key, value]) => ({ key,value }))
  }
}
</script>