<template>
  <div
    id="app"
    class="h-100"
    :class="[skinClasses]"
  >
    <component :is="layout">
      <router-view />
    </component>
  </div>
</template>

<script lang="ts">
import { Component,  Vue, Watch } from 'vue-property-decorator'
import { $themeColors, themeBreakpoints, themeConfig } from '@/config/themeConfig'
import useAppConfig from '@/config/AppConfig'
import { useWindowSize, useCssVar } from '@vueuse/core'
import store from '@/store'

@Component({
  components: {
    LayoutVertical: () => import('@/components/Layout/LayoutDefault/LayoutDefault.vue'),
    LayoutFull: () => import('@/components/Layout/LayoutFull/LayoutFull.vue')
  }
})
export default class App extends Vue {
  windowWidth = useWindowSize().width
  skinClasses = useAppConfig().skinClasses

  @Watch('windowWidth')
  onWindowWidthChange(val) {
    store.commit('app/UPDATE_WINDOW_WIDTH', val)
  }

  get layout() {
    return this.$route.meta.layout === 'full' ? 'layout-full' : 'layout-vertical'
  }

  beforeCreate() {
    const colors = ['primary', 'secondary', 'success', 'info', 'warning', 'danger', 'light', 'dark']

    for (let i = 0, len = colors.length; i < len; i++) {
      $themeColors[colors[i]] = useCssVar(`--${colors[i]}`, document.documentElement).value.trim()
    }

    const breakpoints = ['xs', 'sm', 'md', 'lg', 'xl']
 
    for (let i = 0, len = breakpoints.length; i < len; i++) {
      themeBreakpoints[breakpoints[i]] = Number(useCssVar(`--breakpoint-${breakpoints[i]}`, document.documentElement).value.slice(0, -2))
    }

    const { isRTL } = themeConfig.layout
    document.documentElement.setAttribute('dir', isRTL ? 'rtl' : 'ltr')
  }

  mounted() {
    const { skin } = useAppConfig()

    if (skin.value === 'dark') document.body.classList.add('dark-layout')

    store.commit('app/UPDATE_WINDOW_WIDTH', window.innerWidth)
  }
}
</script>
