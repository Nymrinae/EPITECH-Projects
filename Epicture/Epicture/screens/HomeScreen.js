import React from 'react';
import {
  Picker,
  StatusBar,
  StyleSheet,
  Text,
  TouchableOpacity,
  View
} from 'react-native'

import HomeList from '../components/HomeList'
import Loading from '../components/Loading'
import { getGalleries } from '../api/Gallery'
import { Ionicons } from '@expo/vector-icons';

export default class HomeScreen extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      data: null,
      section: 'hot',
      sort: 'viral',
      isLoading: true
    }

    this._searchImages = this._searchImages.bind(this)
  }
  async componentDidMount() {
    this._searchImages()
  }

  _searchImages = async () => {
    this.setState({ isLoading: true })
    const { section, sort } = this.state
    const res = await getGalleries(section, sort)

    this.setState({ 
      data: res,
      isLoading: false
    })
  }

  render() {
    return (
      <View>
        <StatusBar translucent barStyle="dark-content"/>
        <View style={ styles.optionsContainer }>
          <View style={ styles.pickerContainer }>
            <Picker
              selectedValue={this.state.section}
              onValueChange={(section => this.setState({ section }))}
            >
              <Picker.Item label="hot" value="hot" />
              <Picker.Item label="top" value="top" />
              <Picker.Item label="user" value="user" />
            </Picker>
          </View>
          <View style={ styles.pickerContainer }>
            <Picker
              selectedValue={this.state.sort}
              onValueChange={(sort => this.setState({ sort }))}
            >
              <Picker.Item label="viral" value="viral" />
              <Picker.Item label="top" value="top" />
              <Picker.Item label="time" value="time" />
            </Picker>
          </View>
          <View>
            <TouchableOpacity
              style={{ padding: 10 }}
              onPress={() => this._searchImages()}
            >
              <View>
                <Ionicons name="md-search" size={ 40 }/>
              </View>
            </TouchableOpacity>
          </View>
        </View>
        { (this.state.isLoading)
          ? <Loading />
          : <HomeList data={ this.state.data } />
        }
      </View>
    )
  }
} 

HomeScreen.navigationOptions = {
  title: 'Home'
};

const styles = StyleSheet.create({
  optionsContainer: {
    flex: 1,
    flexDirection: 'row',
    marginBottom: 40
  },
  pickerContainer: {
    flex: 1,
    paddingLeft: 10
  }
});