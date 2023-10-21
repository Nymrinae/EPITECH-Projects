<template>
  <div class="layout-fullpage">
    <router-view />
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator'

@Component
export default class LayoutFull extends Vue {}
</script>

<style lang="scss">
.layout-fullpage {
  background-image: url('https://uploads.toptal.io/blog/image/125351/toptal-blog-image-1517915383695-cfef65b3d04c9f280f5d7f7a50465aeb.png');
  background-position: center;
  background-repeat: no-repeat;
  background-size: cover;
}
</style>
