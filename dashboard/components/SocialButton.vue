<template>
  <v-btn 
    outlined
    :icon="isIcon"
    :color="color"
    :type="type"
    @click="checkNetworkName"
    >
    <v-icon :class="icon" dark> {{ icon }} </v-icon>
  </v-btn>
</template>

<script>
import { mapActions } from 'vuex'

export default {
    props: {
      type: String,
      icon: String,
      color: String,
      isIcon: Boolean,
      networkName: String
    },
  methods: {
    ...mapActions({
      facebook: 'fireAuth/signInWithFacebook',
      google: 'fireAuth/signInWithGoogle',
      twitter: 'fireAuth/signInWithTwitter'
    }),
    checkNetworkName() {
      switch (this.networkName) {
        case 'facebook':
          this.facebook();
          break;
        case 'google':
          this.google();
          break;
        case 'twitter':
          this.twitter();
          break;
      }
    }
  }
}
</script>

<style scoped>
</style>