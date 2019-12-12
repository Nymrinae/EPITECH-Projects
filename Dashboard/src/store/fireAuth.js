import {
  db,
  auth,
  GoogleProvider,
  FacebookProvider,
  TwitterProvider,
  GithubProvider
} from '@/plugins/firebase'
import firebaseAuthErrors from '@/helpers/firebaseAuthErrors.js'

export const strict = false

const state = () => ({
  user: null
})

const getters = {
  getCurrentUser: (state) => {
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
      const res = await auth.createUserWithEmailAndPassword(user.email, user.password)
      const emailID = res.user.email.split('@')[0]

      if (res) {
        const registeredUser = {
          name: emailID,
          email: res.user.email,
          photoURL: res.user.photoURL != null ? res.user.photoURL : `https://eu.ui-avatars.com/api/?name=${emailID}`,
          services: ['weather', 'stockExchange']
        }
        const ref = db.collection('users').doc(res.user.uid)

        await ref.set(registeredUser)
        alert('Successfully registered ! Please login.')
      }
    } catch (e) {
      firebaseAuthErrors(e.code)
    }
  },
  async standardSignIn({ commit }, user) {
    try {
      const res = await auth.signInWithEmailAndPassword(user.email, user.password)
      const emailID = res.user.email.split('@')[0]
      const connectedUser = {
        uid: res.user.uid,
        name: emailID,
        email: res.user.email,
        photoURL: res.user.photoURL != null ? res.user.photoURL : `https://eu.ui-avatars.com/api/?name=${emailID}`
      }

      commit('setUser', connectedUser)
      this.$router.replace({ path: '/dashboard' })
    } catch (e) {
      firebaseAuthErrors(e.code)
    }
  },
  async socialSignIn({ commit }, type) {
    let res = null

    try {
      switch (type) {
        case 'facebook':
          res = await auth.signInWithPopup(FacebookProvider)
          break
        case 'google':
          res = await auth.signInWithPopup(GoogleProvider)
          break
        case 'github':
          res = await auth.signInWithPopup(GithubProvider)
          break
        case 'twitter':
          res = await auth.signInWithPopup(TwitterProvider)
          break
        default:
          res = null
      }

      const emailID = res.user.email.split('@')[0]
      const connectedUser = {
        uid: res.user.uid,
        name: res.user.displayName != null ? res.user.displayName : emailID,
        email: res.user.email,
        photoURL: res.user.photoURL
      }
      commit('setUser', connectedUser)
      this.$router.replace({ path: '/dashboard' })
    } catch (e) {
      firebaseAuthErrors(e.code)
    }
  },
  async signOut({ commit }) {
    await auth.signOut()
    commit('setUser', null)
  }
}

export default {
  state,
  getters,
  mutations,
  actions
}
