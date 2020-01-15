import React from 'react'
import {
  FlatList,
  Image,
  Text,
  View,
  ScrollView,
  StyleSheet
} from "react-native";
import { getAccountImages } from '../api/Account'
import DeleteButton from '../components/DeleteButton'

export default class ProfileImages extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      isLoading: true,
      images: null,
      refreshing: false
    }
  }
  
  async componentDidMount() {
    await this._getImages()
  }

  _renderItem = ({ item, index }) => {
    return (
      <View style={ styles.itemContainer }>
        <View style={ styles.favButtonContainer }>
          <DeleteButton id={item}/>
        </View>
        <Image
          style={ styles.image }
          source={{ uri: item }}
        />
      </View>
    )
  }

  _getImages = async () => {
    const images = await getAccountImages()

    this.setState({ 
      images,
      isLoading: false,
      refreshing: false
    })
  }

  _handleRefresh = () => {
    this.setState({
      refreshing: true
    },
    () => this._getImages())
  }

  render() {
    if (this.state.isLoading) {
      return null
    }
    return (
      <ScrollView>
        <View style={ styles.container }>
          <FlatList
            horizontal
            data={ this.state.images }
            renderItem={ this._renderItem }
            keyExtractor={(item, i) => i.toString() }
            contentContainerStyle={{ paddingBottom: 40 }}
            onRefresh={ this._handleRefresh }
            refreshing={ this.state.refreshing }
            showsHorizontalScrollIndicator={false}
          />
        </View>
      </ScrollView>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
    flexWrap: 'wrap'
  },
  itemContainer: {
    width: 200,
    height: 250,
    marginTop: 24,
    marginLeft: 18,
    marginRight: 18
  },
  image: { 
    flex: 1,
    borderRadius: 12
  },
  favButtonContainer: {
    position: 'absolute',
    right: 12,
    top: 7,
    zIndex: 2
  }
})