import * as React from 'react'
import { Image, Text, TextInput,View, StyleSheet, TouchableOpacity, StatusBar, ScrollView } from 'react-native'
import { Auth } from '../../api'
import { FormState } from '../../types'
export default class LoginForm extends React.Component<any, FormState> {
  constructor(props: any) {
    super(props)

    this.state = {
      email: 'sylvain.nymrinae@gmail.com',
      password: 'test123',
      errorMsg: null
    }
  }

  _checkLogin = async () => {
    const { email, password } = this.state
    const res = await Auth.login({ email, password })

    if (res) {
      this.props.navigation.navigate('Main')
    } else {
      this.setState({ errorMsg: 'Incorrect credentials.'})
    }
  }

  render() {
    return (
      <ScrollView style={styles.container}>
        <StatusBar translucent barStyle="dark-content"/>
        <View>
            <View style={{ marginTop: 60, alignItems: "center", justifyContent: "center" }}>
              <Image
                source={require("../../../assets/logo.png")}
                style={{ width: 100, height: 100, marginTop: -20}}
              />
              <Text style={[styles.text, { marginTop: 10, fontSize: 22, fontWeight: "500" }]}>Epitech AREA</Text>
            </View>
            <View style={{ marginTop: 48, flexDirection: "row", justifyContent: "center" }}>
              <TouchableOpacity style={styles.socialButton}>
                <Image source={require('../../../assets/facebook.png')} style={styles.socialLogo} />
                <Text style={styles.text}>Facebook</Text>
              </TouchableOpacity>

              <TouchableOpacity style={styles.socialButton}>
                <Image source={require("../../../assets/google.png")} style={styles.socialLogo} />
                <Text style={styles.text}>Google</Text>
              </TouchableOpacity>
            </View>

            <Text style={[styles.text, { color: "#ABB4BD", fontSize: 15, textAlign: "center", marginVertical: 20 }]}>or</Text>

            <View>
              <Text style={styles.inputTitle}> Email </Text>
              <TextInput
                style={styles.input}
                onChangeText={ (email) => this.setState({ email })}
              />
              <View style={{ borderBottomColor: "#D8D8D8", borderBottomWidth: 1, paddingTop: -20 }} />
            </View>

            <View style={{ paddingTop: 20 }}>
              <Text style={styles.inputTitle}> Password </Text>
              <TextInput
                secureTextEntry
                style={styles.input}
                onChangeText={ (password) => this.setState({ password })}
              />
              <View style={{ borderBottomColor: "#D8D8D8", borderBottomWidth: 1, paddingTop: -20}} />
            </View>
            <Text style={{ color: '#FF0000', textAlign: 'center', marginTop: 10 }}> { this.state.errorMsg }</Text>
            <TouchableOpacity
              style={styles.submitContainer}
              onPress={ this._checkLogin }
            >
                <Text style={[ styles.text, {
                    color: "#FFF",
                    fontWeight: "600",
                    fontSize: 16
                  }]}
                >
                  Login
                </Text>
            </TouchableOpacity>
            <TouchableOpacity
              onPress={ () => this.props.navigation.navigate('Register')}
            >
              <Text style={[ styles.text, {
                  fontSize: 14,
                  color: "#ABB4BD",
                  textAlign: "center",
                  marginTop: 24
                }]}
              >
                  Don't have an account? <Text style={[styles.text, styles.link]}>Register Now</Text>
              </Text>
            </TouchableOpacity>
        </View>
      </ScrollView>
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
    fontSize: 14
  },
  input: {
    paddingVertical: 12,
    color: "#1D2029",
    fontSize: 14,
    paddingBottom: -10
  }
})