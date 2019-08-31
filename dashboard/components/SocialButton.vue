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
      facebookSignIn: 'fireAuth/signInWithFacebook',
      googleSignIn: 'fireAuth/signInWithGoogle',
      twitterSignIn: 'fireAuth/signInWithTwitter'
    }),
    checkNetworkName() {
      switch (this.networkName) {
        case 'facebook':
          this.facebookSignIn();
          break;
        case 'google':
          this.googleSignIn();
          break;
        case 'twitter':
          this.twitterSignIn();
          break;
      }
    },
    facebookSignIn() {
      alert('bite');
    }

  }
}
</script>

<style scoped>
</style>