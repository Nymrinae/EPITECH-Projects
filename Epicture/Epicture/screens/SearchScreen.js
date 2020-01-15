import React from 'react'
import {
  ScrollView,
  StyleSheet,
  StatusBar,
  Text,
  TextInput,
  View,
  FlatList,
  TouchableOpacity,
} from 'react-native'
import { getImages } from '../api/Gallery'
import { getUserFollowingTags } from '../api/Account'
import SearchHandler from '../components/SearchHandler' 
import HighlightSectionText from '../components/HighlightSectionText'
export default class SearchScreen extends React.Component {

  constructor(props) {
    super(props)
    this.state = {
      text: '',
      searchStr: null,
      type: 0,
      tags: [],
      isLoading: true,
      dataSuccess: false,
      imagesByName: null,
      imagesByTag: null
    }
    this._searchImages = this._searchImages.bind(this);
    this._handleTags = this._handleTags.bind(this);
  }

  componentDidMount = async () => {
    const tags = await getUserFollowingTags()

    this.setState({ tags })
  }

  _searchImages = async () => {
    this.setState({ isLoading: true })
    let { text, searchStr } = this.state
    const search = searchStr ? searchStr : text
    const byName = await getImages(true, search)
    const byTag = await getImages(false, search)

    this.setState({ 
      imagesByName: byName ? byName : null,
      imagesByTag: byTag ? byTag : null,
      isLoading: false,
      dataSuccess: byName && byTag
    });
  }

  _handleTags = async (tag) => {
    this.setState({
      searchStr: tag,
      imagesByName: null,
      imagesByTag: null
    })
    await this._searchImages()
    this.setState({
      text: '',
      searchStr: null
     })
  }

  _renderTagsItems = ({ item }) => {
    return (
      <View style={ styles.tagContainer }>
        <TouchableOpacity
          style={ styles.tags }
          onPress={() => this._handleTags(`${item}`)} 
        >
          <Text> { item } </Text>
        </TouchableOpacity>
      </View>
    )
  }

  render() {
    const searchSmth = <Text style={styles.textIndicators}> Search something !</Text>

    return (
      <View>
        <StatusBar translucent barStyle="dark-content" />
        <TextInput
          style={styles.input}
          placeholder="Search something..."
          onChangeText={(text) => this.setState({ text })}
          onSubmitEditing={() => this._searchImages()}
          value={this.state.text}
        />
        <HighlightSectionText text="MY TAGS" style={{ marginBottom: 10 }} />
        <View style={ styles.tagsContainer }>
          <FlatList
            horizontal
            data={this.state.tags}
            renderItem={ this._renderTagsItems }
            keyExtractor={ (item, i) => i.toString() }
            contentContainerStyle={{ paddingBottom: 20 }}
          />
        </View>
        { this.state.isLoading
          ? searchSmth
          : this.state.dataSuccess
          ? <SearchHandler
              byName={ this.state.imagesByName }
              byTag={ this.state.imagesByTag }
            /> 
          : null
        }
      </View>
    )
  }
}

SearchScreen.navigationOptions = {
  title: 'Search'
};

const styles = StyleSheet.create({
  favoriteButtonContainer: {
    flexDirection: 'row'
  },
  tagContainer: {
    paddingTop: 20
  },
  tags: {
    padding: 6,
    marginLeft: 23,
    borderRadius: 6,
    color: '#666666',
    backgroundColor: '#ededed'
  },
  deleteButton: {
    width: 57,
    height: 57,
    marginRight: 15,
    justifyContent: 'center',
    alignItems: 'center',
    borderWidth: 1,
    borderColor: '#e6e6e6'
  },
  deleteText: {
    color: '#979797',
    fontSize: 30
  },
  headingContainer: {
    justifyContent: 'center',
    alignItems: 'center',
    height: 100,
    borderBottomWidth: 1,
    borderBottomColor: '#ededed'
  },
  heading: {
    fontSize: 20,
    marginTop: 20
  },
  container: {
    flex: 1
  },
  favorite: {
    justifyContent: 'center',
    alignItems: 'center',
    padding: 13,
    marginLeft: 15,
    marginRight: 5,
    borderWidth: 1,
    borderColor: '#e6e6e6',
    marginBottom: 10,
    borderRadius: 4,
    flex: 1
  },
  favoriteText: {
    fontSize: 24,
    color: '#9f9f9f'
  },
  input: {
    height: 60,
    margin: 20,
    backgroundColor: '#ededed',
    borderRadius: 4,
    padding: 10,
    fontSize: 18,
    color: '#666666'
  },
  buttonContainer: {
    flexDirection: 'row',
    justifyContent: 'flex-end'
  },
  button: {
    marginRight: 20,
    marginTop: 15,
    padding: 15,
    paddingLeft: 30,
    paddingRight: 30,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#3b5998',
    borderRadius: 4
  },
  buttonText: {
    color: 'white',
    fontWeight: 'bold'
  },
  favContainer: {
    marginTop: 20,
    paddingTop: 20,
    borderTopWidth: 1,
    borderTopColor: '#ededed'
  },
  favorites: {
    color: '#c9c9c9',
    textAlign: 'center',
    fontSize: 13,
    fontWeight: 'bold',
    marginBottom: 17
  },
  mainContainer: {
    flex: 1
  },
  textIndicators: {
    justifyContent: 'center',
    marginLeft: 150,
    marginTop: 250
  }
})