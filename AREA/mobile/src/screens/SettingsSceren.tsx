import * as React from 'react'
import { StyleSheet, View, StatusBar } from 'react-native'

import Screen from '../components/Screen'

export default class ScreenTwo extends React.Component<any> {
  constructor(props: any) {
    super(props)
  }

  render() {
    return (
      <View style={ styles.container }>
        <StatusBar translucent barStyle="light-content"/>
        <Screen name= {'Screen Two'} />
      </View>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center'
  }
})