<template>
  <LayoutVertical>

    <router-view />

    <template #navbar="{ toggleVerticalMenuActive }">
      <navbar :toggle-vertical-menu-active="toggleVerticalMenuActive" />
    </template>
  </LayoutVertical>
</template>

<script>
import LayoutVertical from './LayoutVertical.vue'
import Navbar from '../Navbar/Navbar.vue'

export default {
  components: {
    LayoutVertical,
    Navbar,
  }
}
</script>
