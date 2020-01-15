import React from 'react'
import { 
  Text,
  StyleSheet
} from 'react-native'

export default class HighlightSectionText extends React.Component {
  constructor(props) {
    super(props)
  }

  render() {
    return (
      <Text style={ styles.text }>
        { this.props.text }
      </Text>
    )
  }
}

const styles = StyleSheet.create({
  text: {
    fontSize: 18,
    marginLeft: 20,
    marginBottom: -10,
    fontWeight: '500',
    textTransform: 'uppercase'
  }
})