<template>
  <v-btn
    outlined
    :icon="isIcon"
    :color="color"
    @click="checkNetworkName"
  >
    <v-icon :class="icon" dark>
      {{ icon }}
    </v-icon>
  </v-btn>
</template>

<script>
/* import { facebookLogin, googleLogin } from '../../api/auth' */

export default {
  props: {
    name: { type: String, default: '' },
    icon: { type: String, default: '' },
    color: { type: String, default: '' },
    isIcon: Boolean,
    networkName: { type: String, default: '' }
  },
  methods: {
    async checkNetworkName() {
      /* this.name === 'facebook'
        ? await facebookLogin()
        : await googleLogin() */
    }
  }
}
</script>

<style scoped>
</style>
