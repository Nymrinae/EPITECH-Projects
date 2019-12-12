<template>
  <div>
    <Sidebar />
    <p style="padding-left: 350px;">
      <v-row
        class="ma-3 pa-6"
        justify="center"
      >
        <v-col lg="6">
          <div v-if="checkServices('weather')">
            <Weather />
          </div>
          <div v-if="checkServices('pokemon')">
            <Pokemon />
          </div>
        </v-col>
        <v-col lg="6">
          <div v-if="checkServices('stockExchange')">
            <StockExchange />
          </div>
          <div v-if="checkServices('reddit')">
            <Reddit />
          </div>
        </v-col>
      </v-row>
    </p>
  </div>
</template>

<script>
import { db } from '@/plugins/firebase'
import Sidebar from '@/components/Dashboard/Sidebar'
import Pokemon from '@/components/Dashboard/Widgets/Pokemon'
import Reddit from '@/components/Dashboard/Widgets/Reddit'
import Weather from '@/components/Dashboard/Widgets/Weather'
import StockExchange from '@/components/Dashboard/Widgets/StockExchange'

export default {
  components: {
    Sidebar,
    Weather,
    Pokemon,
    Reddit,
    StockExchange
  },
  middleware: 'routerAuth',
  data() {
    return {
      services: []
    }
  },
  computed: {
    user() {
      return this.$store.getters['fireAuth/getCurrentUser']
    }
  },
  mounted() {
    this.getUser()
  },
  methods: {
    async getUser() {
      const ref = db.collection('users').doc(this.user.uid)
      let snap = null

      try {
        snap = await ref.get()
        this.services = snap.data().services
      } catch (e) {
        console.log(e)
      }
    },
    checkServices(service) {
      return this.services.includes(service)
    }
  }
}
</script>

<style>

</style>
