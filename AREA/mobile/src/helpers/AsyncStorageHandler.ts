import { AsyncStorage } from 'react-native'

const getInfoFromStorage = async (key: string) => {
  try {
    let data = await AsyncStorage.getItem(key)

    return JSON.parse(data)
  } catch (e) {
    throw e
  }
}

const setInfoInStorage = async (key: string, data: string) => {
  try {
    await AsyncStorage.setItem(key, data)
  } catch (e) {
    throw e
  }
}

export {
  getInfoFromStorage,
  setInfoInStorage
}