import * as React from 'react'
import { StyleSheet, View, StatusBar } from 'react-native'
import Screen from '../components/Screen'
import Card from '../components/Card'

export default class ScreenOne extends React.Component<any> {
  constructor(props: any) {
    super(props)
  }

  render() {
    return (
      <View style={ styles.container }>
        <StatusBar translucent barStyle="light-content"/>
        <Card />
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