import React from "react"
import {
  StatusBar,
  TouchableOpacity,
  View,
} from "react-native"
import ProfileHandler from '../components/ProfileHandler'

import { MaterialCommunityIcons } from '@expo/vector-icons'
export default class ProfileScreen extends React.Component {
  static navigationOptions = ({ navigation }) => {
    return {
      title: 'Profile',
      headerRight: (
        <TouchableOpacity
          onPress={ async () => {
            navigation.navigate('Landing')
          }}
        >
          <MaterialCommunityIcons
            name="logout-variant"
            size={26}
            style={{ marginRight: 15 }}
            color="black"
          />
        </TouchableOpacity>
      )
    }
  }

  constructor(props) {
    super(props)
  }

  render() {
    return (
      <View>
        <StatusBar translucent barStyle="dark-content"/>
        <ProfileHandler />
      </View>
    )
  }
}