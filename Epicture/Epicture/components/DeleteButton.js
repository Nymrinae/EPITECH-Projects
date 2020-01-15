import React from 'react'
import {
  Alert,
  TouchableOpacity,
  View
} from 'react-native'
import { Ionicons } from '@expo/vector-icons'

import { deleteUploadedImage } from '../api/Image'

export default class DeleteButton extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
    }
  }

  _deleteItem = async () => {
    const id = this.props.id.split('/')[3].split('.')[0]

    Alert.alert(
      'Delete from uploaded images',
      'Are you sure you want to delete this image from your uploaded images ?',
      [
        { 
          text: 'Cancel',
          onPress: () => null
        },
        { 
          text: 'OK',
          onPress: async () => {
            await deleteUploadedImage(id)
          }
        }
      ],
      { cancelable: false }
    )
  }

  render() {
    return (
      <TouchableOpacity onPress={ this._deleteItem }>
        <View>
          <Ionicons
            name="md-close-circle"
            size={26}
            color="red"
          />
        </View>
      </TouchableOpacity>
    )
  }
}