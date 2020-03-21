import * as React from 'react'
import { SafeAreaProvider } from 'react-native-safe-area-context'
import { AppearanceProvider } from 'react-native-appearance'

import AppNavigator from './navigation/AppNavigator'

export default class Main extends React.Component {
  render() {
    return (
      <SafeAreaProvider>
        <AppearanceProvider>
          <AppNavigator />
        </AppearanceProvider>
      </SafeAreaProvider>
    )
  }
}
