import axios from 'axios'

const axiosGCalendarInstance = axios.create({
  baseURL: 'https://www.googleapis.com/calendar/v3'
})

const axiosDiscordInstance = axios.create({
  baseURL: 'https://discordapp.com/api'
})

const axiosIntraInstance = axios.create({
  baseURL: 'https://intra.epitech.eu'
})

const axiosFacebookInstance = axios.create({
  baseURL: 'https://graph.facebook.com'
})

const axiosTrelloInstance = axios.create({
  baseURL: 'https://trello.com'
})

export {
  axiosGCalendarInstance,
  axiosDiscordInstance,
  axiosIntraInstance,
  axiosFacebookInstance,
  axiosTrelloInstance
}

// pour l'utiliser tu fais donc import { axiosGCalendarInstance } from 'PATH_VERS_CE_FICHIER'
// et ensuite bah const res = await axiosGCalendarInstance.get/post('URL')