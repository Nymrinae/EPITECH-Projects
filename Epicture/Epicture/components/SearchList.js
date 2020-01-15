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
export default class List extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      data: this.props.data,
      currentImage: {},
      isLoading: false,
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

  _renderItem({ item }) {
    return (
      <View>
        <TouchableOpacity
          style={ styles.itemContainer }
          onPress={() => this._saveImage(item)}
        >
          <Image
            style={styles.image}
            source={{ uri: item.link }}
          />
        </TouchableOpacity>
      </View>
    )
  }

  render() {
    const { author, desc, id, isFavorite, title, link, views } = this.state.currentImage

    return (
      <View>
        <FlatList
          horizontal
          data={this.state.data}
          renderItem={ this._renderItem }
          keyExtractor={ (item, i) => i.toString() }
          contentContainerStyle={{ paddingBottom: 20 }}
          showsHorizontalScrollIndicator={false}
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
                  <TouchableOpacity onPress={ () => this._addToFavorites(id) }>
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
                <Text style={ styles.textToLeft }>
                  { views } views
                </Text>
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
  itemContainer: {
    width: 200,
    height: 200,
    marginTop: 24,
    marginLeft: 18,
    marginRight: 18
  },
  descContainer: {
    flex: 1,
    justifyContent: 'center'
  },
  favoriteContainer: {
    alignItems: 'flex-end',
    justifyContent: 'center',
    marginRight: 20
  },
  image: { 
    flex: 1,
    borderRadius: 12
  },
  smallText: {
    fontSize: 14,
    margin: 10
  },
  mediumText: {
    fontSize: 18,
    margin: 10
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