import React from 'react'
import {
  Text,
  TouchableOpacity,
  View
} from 'react-native'
import { Ionicons } from '@expo/vector-icons'

export default class ModalCardTitle extends React.Component {
  constructor(props) {
    super(props)
  }

  render() {
    return (
      <View style={{ display: 'flex', flexDirection: 'row', margin: 15 }}>
        <Text style={{ fontWeight: 'bold', fontSize: 18 }}> { title } </Text>
        <View style={{ flexGrow: 1 }} />
        <TouchableOpacity onPress={ () => this._hideImage() }>
          <View>
            <Ionicons
              name="md-close"
              size={26}
              style={{ marginRight: 10 }}
              color="black"
            />
          </View>
        </TouchableOpacity>
      </View>
    )
  }
}