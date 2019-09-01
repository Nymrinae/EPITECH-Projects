import firebase, { auth, GoogleProvider } from '@/plugins/firebase'
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
      commit('setUser', newUser.user.uid)
      alert('Account successfully created !')
    } catch (e) {
      firebaseAuthErrors(e.code)
    }

  },
  async basicLogin({ commit }, user) {
    try {
      let connectedUser = await auth.signInWithEmailAndPassword(user.email, user.password)
      commit('setUser', newUser.uid)
      alert('Logged in!') // redirecting to /home or something
    } catch (e) {
      firebaseAuthErrors (e.code)
    }
  },
  async signInWithFacebook() {
    alert('Unimplemented Facebook Login')
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