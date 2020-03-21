<template>
  <v-content class="align">
    <p class="title header">
      {{ header }}
    </p>
    <div
      v-for="(network, n) in networks"
      :key="n"
    >
      <SocialButton
        :name="network.name"
        :color="network.color"
        :is-icon="network.isIcon"
        :icon="network.iconName"
        :network-name="network.name"
      />
    </div>
  </v-content>
</template>

<script>
import SocialButton from './SocialButton'

export default {
  components: {
    SocialButton
  },
  props: {
    type: { type: String, default: '' },
    header: { type: String, default: '' }
  },
  data() {
    return {
      networks: [
        { name: 'facebook', iconName: 'mdi-facebook', color: 'blue', isIcon: true },
        { name: 'google', iconName: 'mdi-google-plus', color: 'red', isIcon: true }
      ]
    }
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
