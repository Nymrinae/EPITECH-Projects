import * as React from 'react'
import { StyleSheet, View } from 'react-native'

import { RegisterForm } from '../components'
export default class RegisterScreen extends React.Component<any> {

  constructor(props: any) {
    super(props)
  }

  render() {
    return (
      <View
        style={{
          flex: 1,
          backgroundColor: 'white',
          justifyContent: 'flex-end',
          marginTop: 40
        }}
      >
        <RegisterForm navigation={this.props.navigation} />
      </View>
    )
  }
}

const styles = StyleSheet.create({
  mainContainer: {
    flex: 1,
    backgroundColor: 'white',
    justifyContent: "flex-end"
  },
  buttonContainer: {
    ...StyleSheet.absoluteFillObject
  },
  button: {
    backgroundColor: 'white',
    height: 70,
    marginHorizontal: 20,
    borderRadius: 35,
    alignItems: 'center',
    justifyContent: 'center'
  }
})