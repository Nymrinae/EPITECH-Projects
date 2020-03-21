import * as React from 'react'
import { Image, StyleSheet } from 'react-native'
import { AppLoading } from 'expo'
import { Asset } from 'expo-asset'
import * as Font from 'expo-font'
import { Ionicons } from '@expo/vector-icons'

import Main from './src/Main'

console.disableYellowBox = true

type State = {
  isReady: boolean
}

export default class App extends React.Component<any> {
  private isReady: boolean
  state: State

  constructor(props: any) {
    super(props)
    this.state = {
      isReady: false
    }
  }

  async _loadAssetsAsync() {
    const imageAssets = cacheImages([
      require('./assets/bg.jpg')
    ])
    const fontAssets = cacheFonts([Ionicons.font])

    await Promise.all([...imageAssets, ...fontAssets])
  }

  render() {
    if (!this.state.isReady) {
      return (
        <AppLoading
          startAsync={ this._loadAssetsAsync }
          onError={ handleLoadingError }
          onFinish={() => this.setState({ isReady: true })}
        />
      )
    }

    return <Main />
  }
}

const cacheImages = (images: Array<string | any>) => {
  return images.map(image => {
    return typeof(image) === 'string'
    ? Image.prefetch(image)
    : Asset.fromModule(image).downloadAsync()
  })
}

const cacheFonts = (fonts: Array<string | any>) => fonts.map(font => Font.loadAsync(font))

const handleLoadingError = (error: Error) => {
  console.warn(error)
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
})