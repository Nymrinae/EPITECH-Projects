import * as React from 'react'
import axios from 'axios'
import { TextInput, View, StatusBar, Button } from 'react-native'
import { auth, TwitterProvider } from '../api/firebase'

export default class TwitterCard extends React.Component<any> {
  constructor(props: any) {
    super(props)

    this.state = {
      content: ''
    }
  }

  async _tweet() {
    const login = await auth.signInWithPopup(TwitterProvider)
  }

  render() {
    return (
      <View>
        <StatusBar barStyle="dark-content" />
        <TextInput placeholder="tweet something" />
        <Button title="tweet" onPress={async () => this._tweet()}/>
      </View>
    )
  }
}