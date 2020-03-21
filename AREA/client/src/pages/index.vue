<template>
  <v-container class="fill-height" fluid>
    <v-row align="center" justify="center">
      <v-col cols="12" sm="8" md="8">
        <v-card class="elevation-12">
          <v-row class="pa-8">
            <v-col cols="8" md="8">
              <v-img
                class="text-center"
                style="margin: 64px auto"
                :src="require('../../assets/img/logo.png')"
                height="200"
                width="200"
              />
              <div class="text-center">
                <h1 class="display-2 font-weight-bold"> ActionREAction </h1>
                <h3 class="title font-weight-black"> Connect your apps together </h3>
              </div>
            </v-col>
            <v-col cols="8" md="4">
              <AuthHandler />
            </v-col>
          </v-row>
        </v-card>
      </v-col>
    </v-row>
  </v-container>
</template>

<script>
import { AuthHandler } from '../components'

export default {
  components: {
    AuthHandler
  },
  props: {
    source: { type: String, default: null }
  }
}
</script>
