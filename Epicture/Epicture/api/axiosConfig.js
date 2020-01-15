import axios from 'axios'
import { CLIENT_ID } from 'react-native-dotenv'
import { getUserInfosFromStorage } from '../helpers/AsyncStorageHandler'

const getAccessToken = async () => {
  const token = await getUserInfosFromStorage('accessToken')

  return token
}

export const unAuthedInstance = axios.create({
  baseURL: 'https://api.imgur.com',
  headers: {
    'Authorization': `Client-ID ${CLIENT_ID}`
  }
});

export const authedInstance = axios.create({
  baseURL: 'https://api.imgur.com',
  headers: {
    'Authorization': `Bearer ${getAccessToken()}`
  }
})