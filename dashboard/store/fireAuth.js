import firebase, { auth, GoogleProvider } from '@/plugins/firebase'

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
    let newUser = await auth.createUserWithEmailAndPassword(user.email, user.password)

    if (newUser) {
      commit('setUser', newUser.user.uid)
      alert('Account successfully created !');
    }
    else
      alert('Cannot create your account')
  },
  async basicLogin({ commit }, user) {
    let connectedUser = await auth.signInWithEmailAndPassword(user.email, user.password)

    if (connectedUser)
      commit('setUser', newUser.uid)
    else
      alert('Cannot log in into your account')
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