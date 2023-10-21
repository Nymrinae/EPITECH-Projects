import Vue from 'vue'
import Vuex from 'vuex'
import modules from './modules'
import createPersistedState from 'vuex-persistedstate'

Vue.use(Vuex)

export default new Vuex.Store({
  strict: process.env.DEV,
  modules,
  plugins: [
    createPersistedState({
      key: 'OGG_State',
      reducer(store) {
        return ({
          auth: store.auth,
          app: store.app,
          game: store.game,
          shop: store.shop,
          user: store.user
        })
      }
    })
  ]
})
