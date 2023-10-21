<template>
  <p class="clearfix mb-0">
    <span class="float-md-left d-block d-md-inline-block mt-25">
      COPYRIGHT © {{ new Date().getFullYear() }}
      <b-link
        class="ml-25"
        href="#"
        target="_blank"
      > {{ appName }}</b-link>
      <span class="d-none d-sm-inline-block">, All rights Reserved</span>
    </span>

    <!-- <span class="float-md-right d-none d-md-block">Hand-crafted &amp; Made with
      <feather-icon
        icon="HeartIcon"
        size="21"
        class="text-danger stroke-current"
      />
    </span> -->
  </p>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator'
import { themeConfig } from '@/config/themeConfig'

@Component
export default class AppFooter extends Vue {
  appName = themeConfig.app.appName
}
</script>
