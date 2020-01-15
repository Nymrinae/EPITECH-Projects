import React from 'react'
import {
  Alert,
  FlatList,
  Image,
  Modal,
  StatusBar,
  StyleSheet,
  TouchableOpacity,
  Text,
  View,
} from 'react-native'
import { Card } from 'react-native-elements'
import { Ionicons } from '@expo/vector-icons'

import { 
  addImageToFavorites,
  getAccountFavorites
} from '../api/Account'

import { Foundation } from '@expo/vector-icons'
import FavoriteButton from '../components/FavoriteButton'

export default class HomeList extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      data: this.props.data,
      currentImage: {},
      isModalVisible: false
    }
    this._renderItem = this._renderItem.bind(this)
    this._saveImage = this._saveImage.bind(this)
    this._hideImage = this._hideImage.bind(this)
    this._addToFavorites = this._addToFavorites.bind(this)
  }

  _saveImage = async item => {
    item.isFavorite = await this._isFavorite(item.id)

    this.setState({
      currentImage: item,
      isModalVisible: true
    })
  }

  _renderItem({ item }) {
    const { author, link, points, title } = item

    return (
      <View>
        <TouchableOpacity
          style={ styles.itemContainer }
          onPress={() => this._saveImage(item)}
        >
        <Image
          style={ styles.image }
          source={{ uri: link }}
        />
        </TouchableOpacity>
      </View>
    )
  }

  _hideImage = () => this.setState({ isModalVisible: false })

  _addToFavorites = (id) => {
    const { isFavorite } = this.state.currentImage

    Alert.alert(
      `${isFavorite ? 'Delete From' : 'Add To'} Favorites`,
      `Are you sure you want to ${isFavorite ? 'delete' : 'add'} this image ${isFavorite ? 'from' : 'to'} your favorites ?`,
      [
        { 
          text: 'Cancel',
          onPress: () => this._hideImage()
        },
        { 
          text: 'OK',
          onPress: async () => {
            await addImageToFavorites(id)
            this._hideImage()
          }
        }
      ],
      { cancelable: false }
    )
  }

  _isFavorite = async (id) => {
    let res = await getAccountFavorites()
    const isFavorite = res.filter(image => image.id === id)

    return isFavorite.length
  }

  render() {
    const { author, desc, title, link, isFavorite, points } = this.state.currentImage

    return (
      <View style={{ marginTop: 20 }}>
        <FlatList
          data={this.state.data}
          renderItem={ this._renderItem}
          keyExtractor={ (item, i) => i.toString() }
          contentContainerStyle={{ paddingLeft: 10, paddingBottom: 40 }}
          showsHorizontalScrollIndicator={false}
          numColumns={2}
        />
        <Modal
          animationType="slide"
          visible={this.state.isModalVisible}
          transparent
          style={ styles.modal }
        >
          <View style={ styles.modalView }>
            <StatusBar translucent barStyle="dark-content"/>
            <Card
              title={
                <View style={ styles.modalCardContainer }>
                  <Text style={ styles.modalCardTitle }>
                    { title }
                  </Text>
                  <View style={ styles.modalCardAlign } />
                  <TouchableOpacity onPress={ () => this._addToFavorites(link.split('/')[3].split('.')[0]) }>
                    <View style={ styles.modalCardIconHeart }>
                      <Ionicons
                        name={ `md-heart${isFavorite ? '-dislike' : ''}`}
                        size={26}
                        color={ isFavorite ? 'black' : 'red' }
                      />
                    </View>
                  </TouchableOpacity>
                  <TouchableOpacity onPress={ () => this._hideImage() }>
                    <View style={ styles.modelCardIconClose }>
                      <Ionicons
                        name="md-close"
                        size={26}
                        color="black"
                      />
                    </View>
                  </TouchableOpacity>
                </View>
              }
              titleStyle={{ textAlign: 'left' }}
              image={{ uri: link }}
              imageStyle={{ width: 200, height: 400 }}
            >
              <TouchableOpacity
                onPress={() => this._hideImage() }
              >
              </TouchableOpacity>
              <Text>
                { desc ? desc : 'No description' }
              </Text>
              <View>
                <View style={{ flexDirection: 'row' }}>
                  <Foundation name="arrow-up" size={ 18 } color='orange' />
                  <Text> { points } points </Text>
                </View>
                <Text style={ styles.textToRight }>
                  { author }
                </Text>
              </View>
            </Card>
          </View>
        </Modal>
      </View>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    marginBottom: 5
  },
  descContainer: { 
    flex: 1,
    flexDirection: 'row'
  },
  authorText: {
    textAlign: 'right',
    fontStyle: 'italic'
  },
  itemContainer: {
    width: 200,
    height: 200,
    padding: 10
  },
  image: { 
    flex: 1,
    borderRadius: 12
  },
  favButtonContainer: {
    position: 'absolute',
    right: 15,
    top: 15,
    zIndex: 2
  },
  modal: {
    margin: 0,
    borderRadius: 16,
    alignItems: undefined,
    justifyContent: undefined
  },
  modalView: {
    backgroundColor: 'rgba(100, 100, 100, 0.3)',
    flex: 1,
    justifyContent: 'center'
  },
  textToLeft: {
    textAlign: 'left',
    fontStyle: 'italic'
  },
  textToRight: {
    textAlign: 'right',
    fontStyle: 'italic'
  },
  modalCardAlign: {
    flexGrow: 1
  },
  modalCardContainer: {
    display: 'flex',
    flexDirection: 'row',
    margin: 15
  },
  modalCardTitle: {
    fontWeight: 'bold',
    fontSize: 16
  },
  modalCardIconHeart: {
    marginRight: 20
  },
  modalCardIconClose: {
    marginRight: 10
  }
})