<template>
  <v-content class="align">
    <p class="title header"> {{ header }} </p>
    <div
      v-for="network in networks"
      :key="network">
      <SocialButton
        :type="type"
        :color="network.color"
        :isIcon="network.isIcon"
        :icon="network.iconName"
        :networkName="network.name"
      />
    </div>
  </v-content>
</template>

<script>
import SocialButton from '@/components/SocialButton'

export default {
  data() {
    return {
      networks: [
        { name: 'facebook', iconName: 'mdi-facebook', color: 'blue', isIcon: true },
        { name: 'google', iconName: 'mdi-google-plus', color: 'red', isIcon: true },
        { name: 'twitter', iconName: 'mdi-twitter', color: 'blue', isIcon: true }
      ]
    }
  },
  props: {
    type: String,
    header: String
  },
  components: {
      SocialButton
  }
}
</script>

<style scoped>
div {
  display: inline-block;
  width: 20%;
  height: 50%;
  position: relative;
  margin: auto;
}

.align {
  text-align: center;
}

.header {
  padding-top: 15px;
}

.footer {
  padding-bottom: 15px;
}
</style>