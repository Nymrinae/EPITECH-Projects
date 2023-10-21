import { Module, VuexModule, Action, Mutation } from 'vuex-module-decorators'
import { themeConfig, themeBreakpoints } from '@/config/themeConfig'

@Module({
  namespaced: true
})
export default class AppModule extends VuexModule {
  isVerticalMenuCollapsed = themeConfig.layout.menu.isCollapsed
  windowWidth = 0
  shallShowOverlay = false

  layout = {
    isRTL: themeConfig.layout.isRTL,
    skin: localStorage.getItem('vuexy-skin') || themeConfig.layout.skin,
    routerTransition: themeConfig.layout.routerTransition,
    type: themeConfig.layout.type,
    menu: {
      hidden: themeConfig.layout.menu.hidden,
    },
    navbar: {
      type: themeConfig.layout.navbar.type,
      backgroundColor: themeConfig.layout.navbar.backgroundColor,
    },
    footer: {
      type: themeConfig.layout.footer.type,
    }
  }

  get currentBreakpoint() {
    const { windowWidth } = this

    if (windowWidth >= themeBreakpoints.xl) return 'xl'
    if (windowWidth >= themeBreakpoints.lg) return 'lg'
    if (windowWidth >= themeBreakpoints.md) return 'md'
    if (windowWidth >= themeBreakpoints.sm) return 'sm'
    return 'xs'
  }

  @Mutation
  TOGGLE_OVERLAY(val: any) {
    this.shallShowOverlay = val ?? !this.shallShowOverlay
  }

  @Mutation
  UPDATE_VERTICAL_MENU_COLLAPSED(val: boolean) {
    this.isVerticalMenuCollapsed = val
  }

  @Mutation
  UPDATE_WINDOW_WIDTH(val: number) {
    this.windowWidth = val
  }

  @Mutation
  TOGGLE_RTL() {
    this.layout.isRTL = !this.layout.isRTL
    document.documentElement.setAttribute('dir', this.layout.isRTL ? 'rtl' : 'ltr')
  }

  @Mutation
  UPDATE_SKIN(skin) {
    this.layout.skin = skin

    // Update value in localStorage
    localStorage.setItem('vuexy-skin', skin)

    // Update DOM for dark-layout
    if (skin === 'dark') document.body.classList.add('dark-layout')
    else if (document.body.className.match('dark-layout')) document.body.classList.remove('dark-layout')
  }

  @Mutation
  UPDATE_ROUTER_TRANSITION(val) {
    this.layout.routerTransition = val
  }

  @Mutation
  UPDATE_LAYOUT_TYPE(val) {
    this.layout.type = val
  }

  @Mutation
  UPDATE_NAV_MENU_HIDDEN(val) {
    this.layout.menu.hidden = val
  }

  @Mutation
  UPDATE_NAVBAR_CONFIG(obj) {
    Object.assign(this.layout.navbar, obj)
  }

  @Mutation
  UPDATE_FOOTER_CONFIG(obj) {
    Object.assign(this.layout.footer, obj)
  }
}