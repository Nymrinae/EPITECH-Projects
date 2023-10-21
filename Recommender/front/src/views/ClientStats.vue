<template>
  <div>
    <b-row>
      <b-col cols="12" md="6">
        <b-card>
          <ClientClustering />
          <ClientGeneralStats />
        </b-card>
      </b-col>
      <b-col cols="12" md="6">
        <b-card>
          <ClientTicketsStats />
        </b-card>
      </b-col>
    </b-row>
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator'

@Component({
  components: {
    ClientClustering: () => import('@/components/Client/ClientClustering.vue'),
    ClientGeneralStats: () => import('@/components/Client/ClientGeneralStats.vue'),
    ClientTicketsStats: () => import('@/components/Client/ClientTicketsStats.vue')
  }
})
export default class ClientStats extends Vue {
  stats = []
}
</script>