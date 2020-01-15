import React from 'react'
import {
  Image,
  StyleSheet,
  Text,
  View,
  TouchableOpacity
} from "react-native";
import { 
  getUserBasicInformation,
  getUserAlbumsCount,
  getUserCommentsCount,
  getUserImagesCount
} from '../api/Account'
import { Ionicons } from '@expo/vector-icons';

import ProfileImages from './ProfileImages'
import FavoriteImages from '../components/FavoriteImages'
import { convertTimestampToDate } from '../helpers/functions'
import { getUserInfosFromStorage } from '../helpers/AsyncStorageHandler'

export default class ProfileHeader extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      isLoading: true,
      user: null,
      activeState: 0
    }

    this._changeTab = this._changeTab.bind(this)
  }

  async componentDidMount() {
    const username = await getUserInfosFromStorage('accountUsername')
    const user = await getUserBasicInformation(username)
    const nbAlbums = await getUserAlbumsCount(username)
    const nbComments = await getUserCommentsCount(username)
    const nbImages = await getUserImagesCount(username)

    if (user) {
      user.stats = [
        { name: `Comment${nbComments > 1 ? 's' : ''}`, value: nbComments },
        { name: `Image${nbImages > 1 ? 's' : ''}`, value: nbImages },
        { name: `Album${nbAlbums > 1 ? 's' : ''}`, value: nbAlbums }
      ]
      this.setState({ 
        user,
        isLoading: false
      })
    }
  }

  _changeTab = (value) => this.setState({ activeState: value })

  render() {
    if (this.state.isLoading) {
      return null
    }

    const { avatar, created, reputation_name, url } = this.state.user
    const stats = this.state.user.stats

    return (
      <View>
        <View style={{ alignSelf: 'center' }}>
          <View style={ styles.profileImage }>
            <Image
              source={{ uri: avatar }}
              style={ styles.image }
              resizeMode="contain"
            />
          </View>
          <View style={ styles.userInfosContainer }>
            <Text style={ styles.username }> { url } </Text>
            <Text style={ styles.reputationName }> { reputation_name } </Text>
            <Text style={ styles.createdDate }> Created {convertTimestampToDate(created) } </Text>
          </View>
          <View style={ styles.userStatsContainer }>
            {
              stats.map((key, i) => (
                <View key={i} style={ styles.userStatsBox }>
                  <Text style={ styles.statsTextNumber }> { key.value } </Text>
                  <Text style={ styles.statsTextDesc }> { key.name } </Text>
                </View> 
              ))
            }
          </View>
        </View>
        <View style={{ 
          flexDirection: 'row',
          justifyContent: 'space-around',
          marginTop: 20,
          padding: 10,
          borderTopWidth: 1,
          borderBottomWidth: 1,
          borderTopColor: '#EAE5E5',
          borderBottomColor: '#EAE5E5'
        }}>
          <TouchableOpacity onPress={ () => this._changeTab(0) }>
            <Ionicons
              name="md-images"
              size={26}
              color={ !this.state.activeState ? 'green' : 'black'}
            />
          </TouchableOpacity>
          <TouchableOpacity onPress={ () => this._changeTab(1) }>
            <Ionicons
              name="md-heart"
              size={26}
              color={ this.state.activeState ? 'red' : 'black' }
            />
          </TouchableOpacity>
        </View>
        { this.state.activeState
          ? <FavoriteImages />
          : <ProfileImages />
        }
      </View>
    )
  }
}

const styles = StyleSheet.create({
  profileImage: {
    marginTop: 20,
    alignSelf: 'center'
  },
  image: { 
    width: 150,
    height: 150,
    borderRadius: 37.5
  },
  userInfosContainer: {
    alignSelf: 'center',
    alignItems: 'center', 
    marginTop: 16
  },
  username: {
    fontFamily: "geo",
    fontWeight: "500",
    fontSize: 26, 
    paddingBottom: 5
  },
  reputationName: {
    fontWeight: "100",
    fontSize: 14,
    paddingBottom: 5
  },
  createdDate: {
    fontWeight: "normal",
    fontStyle: "italic",
    fontSize: 14
  },
  userStatsContainer: {
    flexDirection: 'row',
    alignSelf: 'center',
    marginTop: 32 
  },
  userStatsBox: {
    alignItems: 'center',
    flex: 1
  },
  statsTextNumber: {
    fontFamily: "geo",
    fontWeight: "bold",
    fontSize: 24,
    paddingBottom: 5
  },
  statsTextDesc: {
    fontSize: 14,
    color: 'gray',
    textTransform: "uppercase"
  }
});