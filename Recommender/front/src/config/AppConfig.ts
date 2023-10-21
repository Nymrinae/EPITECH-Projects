import { computed, watch } from '@vue/composition-api'
import store from '@/store'

export default function useAppConfig() {
  // ------------------------------------------------
  // isVerticalMenuCollapsed
  // ------------------------------------------------
  const isVerticalMenuCollapsed = computed({
    get: () => store.state.app.isVerticalMenuCollapsed,
    set: val => {
      store.commit('app/UPDATE_VERTICAL_MENU_COLLAPSED', val)
    },
  })

  // ------------------------------------------------
  // RTL
  // ------------------------------------------------
  const isRTL = computed({
    get: () => store.state.app.layout.isRTL,
    set: val => {
      store.commit('app/TOGGLE_RTL', val)
    },
  })

  // ------------------------------------------------
  // Skin
  // ------------------------------------------------
  const skin = computed({
    get: () => store.state.app.layout.skin,
    set: val => {
      store.commit('app/UPDATE_SKIN', val)
    },
  })

  const skinClasses = computed(() => {
    if (skin.value === 'bordered') return 'bordered-layout'
    if (skin.value === 'semi-dark') return 'semi-dark-layout'

    // Do not return any class for dark layout because dark layout updates class in body
    // Do not return any class for light layout as that is default layout
    return null
  })

  // ------------------------------------------------
  // routerTransition
  // ------------------------------------------------
  const routerTransition = computed({
    get: () => store.state.app.layout.routerTransition,
    set: val => {
      store.commit('app/UPDATE_ROUTER_TRANSITION', val)
    },
  })

  // *===============================================---*
  // *--------- LAYOUT ---------------------------------------*
  // *===============================================---*

  // ------------------------------------------------
  // layoutType
  // ------------------------------------------------

  const layoutType = computed({
    get: () => store.state.app.layout.type,
    set: val => {
      store.commit('app/UPDATE_LAYOUT_TYPE', val)
    },
  })

  // Reset skin if skin is semi-dark and move to horizontal layout
  watch(layoutType, val => {
    if (val === 'horizontal' && skin.value === 'semi-dark') skin.value = 'light'
  })

  // ------------------------------------------------
  // isNavMenuHidden
  // ------------------------------------------------
  const isNavMenuHidden = computed({
    get: () => true, // store.state.app.layout.menu.hidden,
    set: val => {
      store.commit('app/UPDATE_NAV_MENU_HIDDEN', val)
    },
  })

  // *===============================================---*
  // *--------- NAVBAR ---------------------------------------*
  // *===============================================---*

  const navbarBackgroundColor = computed({
    get: () => store.state.app.layout.navbar.backgroundColor,
    set: val => {
      store.commit('app/UPDATE_NAVBAR_CONFIG', { backgroundColor: val })
    },
  })

  const navbarType = computed({
    get: () => store.state.app.layout.navbar.type,
    set: val => {
      store.commit('app/UPDATE_NAVBAR_CONFIG', { type: val })
    },
  })

  // *===============================================---*
  // *--------- FOOTER ---------------------------------------*
  // *===============================================---*

  const footerType = computed({
    get: () => store.state.app.layout.footer.type,
    set: val => {
      store.commit('app/UPDATE_FOOTER_CONFIG', { type: val })
    },
  })

  return {
    isVerticalMenuCollapsed,
    isRTL,
    skin,
    skinClasses,
    routerTransition,

    // Navbar
    navbarBackgroundColor,
    navbarType,

    // Footer
    footerType,

    // Layout
    layoutType,
    isNavMenuHidden,
  }
}
