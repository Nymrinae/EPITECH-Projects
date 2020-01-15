import React from 'react'
import {
  TouchableOpacity,
  View
} from 'react-native'
import { Ionicons } from '@expo/vector-icons'
import { addImageToFavorites } from '../api/Account'

export default class FavoriteButton extends React.Component {
  constructor(props) {
    super(props)

    this._changeLikedState = this._changeLikedState.bind(this)
  }

  _changeLikedState = async () => {
    await addImageToFavorites(this.props.id)
  }

  render() {
    return (
      <TouchableOpacity onPress={ () => this._changeLikedState() }>
        <View>
          <Ionicons
            name="md-heart"
            size={26}
            color="red"
          />
        </View>
      </TouchableOpacity>
    )
  }
}