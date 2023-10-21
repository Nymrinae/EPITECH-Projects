// Theme Colors
// Initially this will be blank. Later on when app is initialized we will assign bootstrap colors to this from CSS variables.
export const $themeColors = {}

// App Breakpoints
// Initially this will be blank. Later on when app is initialized we will assign bootstrap breakpoints to this object from CSS variables.
export const themeBreakpoints = {
  xl: 0,
  lg: 0,
  md: 0,
  sm: 0,
  xs: 0
}

// APP CONFIG
export const themeConfig = {
  app: {
    appName: 'T-DAT-901 - Recommender', // Will update name in navigation menu (Branding)
    appDescription: 'Recommend items to your clients',
    // eslint-disable-next-line global-require
    appLogoImage: require('@/assets/logo_extended.png'), // Will update logo in navigation menu (Branding)
  },
  layout: {
    isRTL: false,
    skin: 'dark', // light, dark, bordered, semi-dark
    routerTransition: 'zoom-fade', // zoom-fade, slide-fade, fade-bottom, fade, zoom-out, none
    type: 'vertical', // vertical, horizontal
    menu: {
      hidden: true,
      isCollapsed: false,
    },
    navbar: {
      // ? For horizontal menu, navbar type will work for navMenu type
      type: 'floating', // static , sticky , floating, hidden
      backgroundColor: '', // BS color options [primary, success, etc]
    },
    footer: {
      type: 'static', // static, sticky, hidden
    },
    customizer: true,
    enableScrollToTop: true,
  },
}
