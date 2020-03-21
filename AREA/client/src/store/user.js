/* eslint-disable */
import { auth } from '../api/firebase'
import axiosInstance from '../api/axiosConfig'

const state = () => ({
  currentUser: {
    displayName: null,
    uid: null,
    email: null,
    photoURL: null,
    services: []
  },
  hasDiscordWebhook: false,
  webHookLink: '',
  subreddit: ''
})

const getters = {
  getDiscordWebhookState: (state) => state.hasDiscordWebhook,
  getDiscordWebhookLink: (state) => state.webHookLink,
  getSubreddit: (state) => state.subreddit,
  getUser: (state) => state.currentUser,
  getServices: (state) => state.currentUser.services
}

const mutations = {
  SET_USER: (state, { currentUser }) => state.currentUser = currentUser,
  SET_WEBHOOK: (state, webHookLink) => state.webHookLink = webHookLink,
  SET_SUBREDDIT: (state, subreddit) => state.subreddit = subreddit,
  ADD_SERVICE: (state, service) => state.currentUser.services.push(service),
  REMOVE_SERVICE: (state, service) => state.currentUser.services.splice(service, 1),
  HAS_DISCORD_WEBHOOK: (state) => state.hasDiscordWebhook = !state.hasDiscordWebhook
}

const actions = {
  getUserInfo: async ({ commit }) => {
    try {
      auth.onAuthStateChanged(user => {
        if (user) {
          const { displayName, uid, email, photoURL } = user

          const currentUser = {
            displayName,
            uid,
            email,
            photoURL,
            services: []
          }
          commit('SET_USER', { currentUser })
        }
      })
    } catch(e) {
      console.log(e)
    }
  },
  addService: ({ commit }, service) => {
    commit('ADD_SERVICE', service)
  },
  removeService: ({ commit }, service) => {
    commit('REMOVE_SERVICE', service)
  },
  updateUser: async ({ commit }, data)  => {
    const res = await axiosInstance.patch('/user/update', {
      uid: data.uid,
      service: data.service
    })
  },
  setWebhook: async ({ commit }, data) => {
    commit('HAS_DISCORD_WEBHOOK')
    commit('SET_WEBHOOK', data.discordWebhook)

    return true
  },
  setSubreddit: async ({ commit }, data) => {
    /* const res = await axiosInstance.post('/setsubreddit', {
      subreddit: data
    }) */

    console.log(data)
    commit('SET_SUBREDDIT', data)

    return true
  }
}

export {
  state,
  getters,
  mutations,
  actions
}