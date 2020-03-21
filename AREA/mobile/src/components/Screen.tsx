import * as React from 'react'
import { Text, View, StatusBar } from 'react-native'

type ScreenProps = {
  name: string
}

export default class Screen extends React.Component<ScreenProps> {
  constructor(props: ScreenProps) {
    super(props)
  }

  render() {
    return (
      <View>
        <StatusBar barStyle="dark-content" />
        <Text> { this.props.name } </Text>
      </View>
    )
  }
}