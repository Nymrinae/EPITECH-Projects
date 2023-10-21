<template>
  <div class="navbar-container d-flex content align-items-center">
    <div class="bookmark-wrapper align-items-center flex-grow-1 d-flex">
      <feather-icon
        icon="HomeIcon"
        size="24"
        class="cursor-pointer ml-1 mr-2"
        @click="$router.push('/')"
        v-b-tooltip.bottom="'Return to Home'"
      />
      <h4 class="pt-1"> {{ appName }} </h4>
    </div>
    <b-navbar-nav class="nav align-items-center ml-auto">
      <b-img
        :src="appLogo"
        alt="logo"
        fluid
        width="128"
      />
    </b-navbar-nav>
  </div>
</template>

<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator'
import { themeConfig } from '@/config/themeConfig'

@Component
export default class Navbar extends Vue {
  @Prop() toggleVerticalMenuActive

  appName = themeConfig.app.appName
  appLogo = themeConfig.app.appLogoImage
}
</script>
