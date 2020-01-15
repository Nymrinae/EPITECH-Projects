import React from 'react'
import {
  ActivityIndicator,
  View
} from 'react-native'

export default class Loading extends React.Component {
  render() {
    return (
      <View style={{ marginTop: 300 }}>
        <ActivityIndicator size="large" color="#0c9"/>
      </View>
    )
  }
}