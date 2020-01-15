import { AsyncStorage } from 'react-native'

module.exports = {
  getUserInfosFromStorage: async (data) => {
    try {
      let infos = await AsyncStorage.getItem('userInfos')
      infos = JSON.parse(infos, null, 2)
  
      switch (data) {
        case 'accessToken':
          return infos.accessToken
        case 'accountId':
          return infos.accountId
        case 'accountUsername':
          return infos.accountUsername
        case 'all':
          return infos
        default:
          return null
      }
    } catch (e) {
      throw e
    }
  },
  setInfosInStorage: async (key, data) => {
    try {
      await AsyncStorage.setItem(key, data)
    } catch (e) {
      throw e
    }
  },
  clearStorage: async () => {
    try {
      await AsyncStorage.clear()
    } catch(e) {
      throw e
    }
  }
}