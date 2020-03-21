import * as React from 'react'
import { Image, Text, TextInput,View, StyleSheet, TouchableOpacity, StatusBar, ScrollView, KeyboardAvoidingView } from 'react-native'
import { Auth } from '../../api'
import { FormState } from '../../types'
import { Ionicons } from '@expo/vector-icons'
import { Avatar } from 'react-native-elements'
import * as ImagePicker from 'expo-image-picker'

export default class RegisterForm extends React.Component<any, any> {
  constructor(props: any) {
    super(props)
    this.state = {
      avatar: null,
      username: null,
      email: null,
      password: null,
      errorMsg: null
    }
  }

  _checkRegister = async () => {
    const { avatar, email, password, username } = this.state
    const res = await Auth.register({ avatar, username, email, password })

    if (res) {
      this.props.navigation.navigate('Main')
    }
  }
  
  _handlePickAvatar = async () => {
    let res = await ImagePicker.launchImageLibraryAsync({
      mediaTypes: ImagePicker.MediaTypeOptions.Images,
      allowsEditing: true,
      aspect: [4, 3]
    })

    if (!res.cancelled) {
      this.setState({ avatar: res.uri })
    }
  }

  render() {
    return (
      <KeyboardAvoidingView
        behavior="position"
        style={styles.container}
        keyboardVerticalOffset={-50}
        enabled
      >
        <StatusBar translucent barStyle="dark-content" />
        <View>
          <View style={{ marginTop: 60, alignItems: "center", justifyContent: "center" }}>
            <Image
              source={require("../../../assets/logo.png")}
              style={{ width: 100, height: 100 }}
            />
            <Text style={[styles.text, { marginTop: 10, fontSize: 22, fontWeight: "500", paddingBottom: 32 }]}>Epitech AREA</Text>
          </View>
          <View>
            <TouchableOpacity
              style={{ alignItems: 'center', paddingBottom: 24 }}
              onPress={ this._handlePickAvatar }>
              { this.state.avatar ? <Avatar rounded size={96} source={{ uri: this.state.avatar }} />
                                  : <Avatar rounded size={96} icon={{ name: 'add' }}/>
              }
            </TouchableOpacity>
          </View>
          <View style={{ paddingBottom: 20 }}>
            <Text style={styles.inputTitle}> Username </Text>
            <TextInput
              style={styles.input}
              onChangeText={ (username) => this.setState({ username })}
            />
            <View style={{ borderBottomColor: "#D8D8D8", borderBottomWidth: 1, marginTop: -10 }} />
          </View>
          <View>
            <Text style={styles.inputTitle}> Email </Text>
            <TextInput
              style={styles.input}
              onChangeText={ (email) => this.setState({ email })}
            />
            <View style={{ borderBottomColor: "#D8D8D8", borderBottomWidth: 1, marginTop: -10 }} />
          </View>

          <View style={{ paddingTop: 20 }}>
            <Text style={styles.inputTitle}> Password </Text>
            <TextInput
              secureTextEntry
              style={styles.input}
              onChangeText={ (password) => this.setState({ password })}
            />
            <View style={{ borderBottomColor: "#D8D8D8", borderBottomWidth: 1, marginTop: -10}} />
          </View>

          <TouchableOpacity
            style={styles.submitContainer}
            onPress={ this._checkRegister }
          >
            <Text style={[ styles.text, {
                color: "#FFF",
                fontWeight: "600",
                fontSize: 16
              }]}
            >
              Register
            </Text>
          </TouchableOpacity>
          <TouchableOpacity
            onPress={ () => this.props.navigation.navigate('Landing')}
          >
            <Text style={[ styles.text, {
                fontSize: 14,
                color: "#ABB4BD",
                textAlign: "right",
                marginTop: 24
              }]}
            >
                Return to <Text style={[styles.text, styles.link]}>Home Screen</Text>
            </Text>
          </TouchableOpacity>
        </View>
      </KeyboardAvoidingView>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    paddingHorizontal: 30
  },
  text: {
    color: "#1D2029"
  },
  socialButton: {
    flexDirection: "row",
    marginHorizontal: 12,
    paddingVertical: 12,
    paddingHorizontal: 30,
    borderWidth: StyleSheet.hairlineWidth,
    borderColor: "rgba(171, 180, 189, 0.65)",
    borderRadius: 4,
    backgroundColor: "#fff",
    shadowColor: "rgba(171, 180, 189, 0.35)",
    shadowOffset: { width: 0, height: 10 },
    shadowOpacity: 1,
    shadowRadius: 20,
    elevation: 5
  },
  socialLogo: {
    width: 16,
    height: 16,
    marginRight: 8
  },
  link: {
    color: "#417374",
    fontSize: 14,
    fontWeight: "500"
  },
  submitContainer: {
    backgroundColor: "#417374",
    fontSize: 16,
    borderRadius: 4,
    paddingVertical: 12,
    marginTop: 32,
    alignItems: "center",
    justifyContent: "center",
    color: "#FFF",
    shadowColor: "rgba(255, 22, 84, 0.24)",
    shadowOffset: { width: 0, height: 9 },
    shadowOpacity: 1,
    shadowRadius: 20,
    elevation: 5
  },
  inputTitle: {
    color: "#ABB4BD",
    fontSize: 14,
  },
  input: {
    paddingVertical: 12,
    color: "#1D2029",
    fontSize: 14
  }
})