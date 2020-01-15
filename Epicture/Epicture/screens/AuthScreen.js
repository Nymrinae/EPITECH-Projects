import React from "react";
import { WebView } from "react-native";
import { parseURL } from '../helpers/functions'
import { setInfosInStorage } from '../helpers/AsyncStorageHandler'
import { CLIENT_ID } from 'react-native-dotenv'
export default class AuthScreen extends React.Component {

  constructor(props) {
    super(props)
    this._onNavigationStateChange = this._onNavigationStateChange.bind(this)
  }

  async _onNavigationStateChange(navState) {
    if (navState.url.startsWith('https://app')) {
      try {
        await setInfosInStorage('userInfos', JSON.stringify(parseURL(navState.url)))
        this.refs.auth.stopLoading();
        this.props.navigation.navigate('Home');
      } catch (e) {
        throw e
      }
    }
  }
  render() {
    return (
      <WebView
        ref={'auth'}
        source={{uri: `https://api.imgur.com/oauth2/authorize?client_id=${CLIENT_ID}&response_type=token`}}
        onNavigationStateChange={ this._onNavigationStateChange }
      />
    )
  }
}

AuthScreen.navigationOptions = {
  header: null
};