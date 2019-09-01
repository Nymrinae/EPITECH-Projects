import { auth, GoogleProvider, FacebookProvider } from '@/plugins/firebase'
import firebaseAuthErrors from '@/helpers/firebaseAuthErrors'

const state = () => ({
  user: null
})

const getters = {
  getCurrentUser: state => {
      return state.user
  }
}

const mutations = {
  setUser: (state, user) => {
      state.user = user
  }
}

const actions = {
  async createAccount({ commit }, user) {
    try {
      let newUser = await auth.createUserWithEmailAndPassword(user.email, user.password)
      commit('setUser', newUser)
      alert('Account successfully created !')
    } catch (e) {
      firebaseAuthErrors(e.code)
    }
  },
  async signInWithEmailAndPassword({ commit }, user) {
    try {
      let connectedUser = await auth.signInWithEmailAndPassword(user.email, user.password)
      commit('setUser', connectedUser)
      alert('Logged in!') // redirecting to /home or something
    } catch (e) {
      firebaseAuthErrors(e.code)
    }
  },
  async signInWithFacebook() {
    return auth.signInWithRedirect(FacebookProvider)
  },
  async signInWithGoogle() {
    return auth.signInWithRedirect(GoogleProvider)
  },
  async signInWithTwitter() {
    alert('Unimplemented Twitter Login')
  },
  async signOut( {commit} ) {
    auth.signOut()
    commit('setUser', null)
  }
}

export default {
  state,
  getters,
  mutations,
  actions
} 