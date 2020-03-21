import React from 'react'
import { TouchableOpacity } from 'react-native'
import { createStackNavigator } from '@react-navigation/stack'
import { DrawerNavigationProp } from '@react-navigation/drawer'
import { Appbar, Avatar, useTheme, Theme } from 'react-native-paper'

import { getCurrentUser } from '../api/User'

import BottomTabs from './BottomTabNavigator';

const Stack = createStackNavigator();

export default class StackNavigator extends React.Component<any, any>  {
  private theme: Theme
  private avatarURL: Promise<string>

  constructor(props: any) {
    super(props)

    this.state = {
      avatar: null
    }
    // this.theme = useTheme()
  }

  async componentDidMount() {
    const data = await getCurrentUser()

    this.setState({ avatar: data.photoURL })
  }

  render() {
    return (
      <Stack.Navigator
        initialRouteName="Home"
        headerMode="screen"
        screenOptions={{
          header: ({ scene, previous, navigation }) => {
            const { options } = scene.descriptor;
            const title =
              options.headerTitle !== undefined
                ? options.headerTitle
                : options.title !== undefined
                ? options.title
                : scene.route.name;

            return (
              <Appbar.Header
                theme={{ colors: { primary: 'white' } }}
              >
                {previous ? (
                  <Appbar.BackAction
                    onPress={navigation.goBack}
                    color={this.theme.colors.primary}
                  />
                ) : (
                  <TouchableOpacity
                    style={{ marginLeft: 10 }}
                    onPress={() => {
                      ((navigation as any) as DrawerNavigationProp<{}>).openDrawer();
                    }}
                  >
                    <Avatar.Image
                      size={40}
                      source={{
                        uri:
                          this.state.avatar,
                      }}
                    />
                  </TouchableOpacity>
                )}
                <Appbar.Content
                  title={ title }
                  titleStyle={{
                    fontSize: 18,
                    fontWeight: 'bold',
                    color: 'black',
                  }}
                />
              </Appbar.Header>
            );
          },
        }}
      >
        <Stack.Screen
          name="Home"
          component={BottomTabs}
          options={({ route }) => {
            const routeName = route.state
              ? route.state.routes[route.state.index].name
              : 'Home';
            return { headerTitle: routeName };
          }}
        />
      </Stack.Navigator>
    )
  }
}