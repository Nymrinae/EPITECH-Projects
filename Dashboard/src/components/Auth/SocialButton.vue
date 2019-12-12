<template>
  <v-btn
    outlined
    :icon="isIcon"
    :color="color"
    :type="type"
    @click="checkNetworkName"
  >
    <v-icon :class="icon" dark>
      {{ icon }}
    </v-icon>
  </v-btn>
</template>

<script>
import { mapActions } from 'vuex'

export default {
  props: {
    type: { type: String, default: '' },
    icon: { type: String, default: '' },
    color: { type: String, default: '' },
    'isIcon': Boolean,
    'networkName': { type: String, default: '' }
  },
  methods: {
    ...mapActions({
      auth: 'fireAuth/socialSignIn'
    }),
    checkNetworkName() {
      this.auth(this.networkName)
    }
  }
}
</script>

<style scoped>
</style>
