import React from 'react'
import { 
  Image,
  StatusBar,
  StyleSheet
} from 'react-native'
import { 
  Block,
  Button,
  Text
} from '../components/UIComponents/index'

export default class StartScreen extends React.Component {
  render() {
    const { navigation } = this.props;
  
    return (
      <Block safe>
        <StatusBar translucent barStyle="dark-content"/>
        <Block center margin={[200, 0]}>
          <Image
            source={{ uri: "https://cdn.discordapp.com/attachments/345175292525936641/632339126288646152/ebiteture.png"}}
            resizeMode="contain"
            style={ styles.logo }
          />
        </Block>
        <Block flex={false} center bottom margin={100}>
          
          <Button
            primary
            onPress={() => navigation.navigate('Auth')}
            style={ styles.button }
          >
            <Text center white caption bold margin={[12, 30]}>
              LOGIN WITH IMGUR
            </Text>
          </Button>
          <Text h3 bold margin={[50, 0, 0, 0]}>
            An Imgur client
          </Text>
          <Text h6 margin={[10, 0]}>
            3rd Year EPITECH Project
          </Text>
        </Block>
      </Block>
    );
  }
}

const styles = StyleSheet.create({
  logo: {
    width: 250,
    height: 250
  },
  button: {
    borderRadius: 30,
    marginTop: 10
  }
});
