/* eslint-disable */
import {
  db,
  auth,
  GoogleProvider,
  FacebookProvider,
  TwitterProvider
} from '../api/firebase'

import axiosInstance from '../api/axiosConfig'

const state = () => ({
  isAuth: false,
  isAuthByFacebook: false,
  isAuthByGoogle: false,
  isAuthByTwitter: false,
  email: null,
  userCreds: {
    facebook: {
      displayName: null,
      username: null,
      photoURL: null,
      accessToken: null
    },
    google: {
      displayName: null,
      username: null,
      photoURL: null,
      secret: null,
      accessToken: null
    },
    twitter: {
      displayName: null,
      username: null,
      photoURL: null,
      secret: null,
      accessToken: null
    },
    intra: {
      token: null
    }
  }
})

const getters = {
  getAuthState: (state) => state.isAuth,
  getEmail: (state) => state.email,
  getIntraToken: (state) => state.userCreds.intra.token,
  getFacebookAuthState: (state) => state.isAuthByFacebook,
  getFacebookCreds: (state) => state.userCreds.facebook,
  getGoogleAuthState: (state) => state.isAuthByGoogle,
  getGoogleCreds: (state) => state.userCreds.google,
  getTwitterAuthState: (state) => state.isAuthByTwitter,
  getTwitterCreds: (state) => state.userCreds.twitter
}

const mutations = {
  CHANGE_USER_STATE: (state) => state.isAuth = !state.isAuth,
  SET_USER_EMAIL: (state, email) => state.email = email,
  SET_INTRA_TOKEN: (state, token) => state.userCreds.intra.token = token,
  SET_FACEBOOK_AUTH_STATE: (state) => state.isAuthByFacebook = !state.isAuthByFacebook,
  SET_FACEBOOK_TOKENS: (state, { creds }) => state.userCreds.facebook = creds,
  SET_GOOGLE_AUTH_STATE: (state) => state.isAuthByGoogle = !state.isAuthByGoogle,
  SET_GOOGLE_TOKENS: (state, { creds }) => state.userCreds.google = creds,
  SET_TWITTER_AUTH_STATE: (state) => state.isAuthByTwitter = !state.isAuthByTwitter,
  SET_TWITTER_TOKENS: (state, { creds }) => state.userCreds.twitter = creds
}

const actions = {
  login: async ({ commit }, user) => {
    try {
      await auth.signInWithEmailAndPassword(user.email, user.password)

      const query = await axiosInstance.post('/users/login', {
        email: user.email
      })

      const res = await auth.signInWithCustomToken(query.data)

      commit('CHANGE_USER_STATE')
      commit('SET_USER_EMAIL', user.email)
      return res
    } catch (e) {
      return false
    }
  },
  register: async ({ commit }, user) => {
    try {
      const res = await axiosInstance.post('/users/register', {
        avatar: '',
        username: user.username,
        email: user.email,
        password: user.password
      })

      commit('CHANGE_USER_STATE')

      return res
    } catch (e) {
      console.log(e)
      return false
    }
  },
  facebookLogin: async ({ commit }) => {
    try {
      const res = await auth.signInWithPopup(FacebookProvider)

      if (res) {
        const { displayName, email, photoURL } = res.user
        const creds = {
          displayName,
          photoURL,
          username: email,
          accessToken: res.credential.accessToken,
        }
        commit('SET_FACEBOOK_TOKENS', { creds })
        commit('SET_FACEBOOK_AUTH_STATE')

        return res
      }

      return (res)
    } catch(e) {
      console.log(e)
      return false
    }
  },
  googleLogin: async ({ commit }) => {
    try {
      const res = await auth.signInWithPopup(GoogleProvider)

      if (res) {
        console.log(res.user)
        const { displayName, email, photoURL } = res.user
        const { accessToken, idToken } = res.credential
        const creds = {
          displayName,
          photoURL,
          username: email,
          accessToken,
          secret: idToken
        }
        console.log(creds)
        commit('SET_GOOGLE_TOKENS', { creds })
        commit('SET_GOOGLE_AUTH_STATE')

        return res
      }
    } catch(e) {
      console.log(e)
      return false
    }
  },
  twitterLogin: async ({ commit }) => {
    try {
      const res = await auth.signInWithPopup(TwitterProvider)

      if (res) {
        const { displayName, photoURL } = res.user
        const { accessToken, secret } = res.credential

        const creds = {
          displayName,
          username: res.additionalUserInfo.username,
          photoURL,
          secret,
          accessToken
        }

        commit('SET_TWITTER_TOKENS', { creds })
        commit('SET_TWITTER_AUTH_STATE')

        return res
      }
    } catch (e) {
      return false
    }
  },
  intraLogin: async ({ commit }, url) => {
    const token = url.split('/')[3]

    const res = await axiosInstance.get('/intra/profile', {
      headers: {
        token
      }
    })

    if (res) {
      commit ('SET_INTRA_TOKEN', token)
      return res
    }
  }
}

export {
  state,
  getters,
  mutations,
  actions
}
