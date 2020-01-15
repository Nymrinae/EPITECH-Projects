import React from 'react'
import {
  ScrollView,
  View
} from 'react-native'
import SearchList from '../components/SearchList'
import HighlightSectionText from '../components/HighlightSectionText'

export default class SearchHandler extends React.Component {
  constructor(props) {
    super(props)
  }
  render() {
    return (
      <ScrollView>
        <View>
          <HighlightSectionText text="By Name" />
          <SearchList data={ this.props.byName } />
          <HighlightSectionText text="By Tags" />
          <SearchList data={ this.props.byTag } />
        </View>
      </ScrollView>
    )
  }
}