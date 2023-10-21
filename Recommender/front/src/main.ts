import Vue from 'vue'
import { BootstrapVue } from 'bootstrap-vue'
import VueCompositionAPI from '@vue/composition-api'
import VRipple from 'vue-ripple-directive'

import router from './router'
import store from './store'
import App from './App.vue'

// Global Components
import FeatherIcon from '@/components/FeatherIcon.vue'
Vue.component(FeatherIcon.name, FeatherIcon)

// Global Mixins
import LoadingMixin from '@/mixins/LoadingMixin'
Vue.mixin(LoadingMixin)

// 3rd party plugins
import '@/libs/toastification'

// Libs
Vue.use(BootstrapVue)
Vue.use(VueCompositionAPI)

// Directives
Vue.directive('ripple', VRipple)

// import styles
import '@/assets/scss/core.scss'
import '@/assets/scss/style.scss'

Vue.config.productionTip = false

export default new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
