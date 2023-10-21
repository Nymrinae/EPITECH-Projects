import { themeBreakpoints } from '@/config/themeConfig'

export default {
  watch: {
    $route() {
      if (this.$store.state.app.windowWidth < themeBreakpoints.xl) {
        this.isVerticalMenuActive = false
      }
    },
  },
}
