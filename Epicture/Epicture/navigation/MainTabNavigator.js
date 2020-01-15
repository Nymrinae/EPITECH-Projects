import React from 'react'
import { Platform } from 'react-native'
import { createStackNavigator, createBottomTabNavigator } from 'react-navigation'

import TabBarIcon from '../components/TabBarIcon'
import HomeScreen from '../screens/HomeScreen'
import SearchScreen from '../screens/SearchScreen'
import UploadScreen from '../screens/UploadScreen'
import ProfileScreen from '../screens/ProfileScreen'

const config = Platform.select({
  web: { headerMode: 'screen' },
  default: {}
})

const HomeStack = createStackNavigator({
    Home: HomeScreen,
  },
  config
)

HomeStack.navigationOptions = {
  tabBarLabel: 'Home',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={
        Platform.OS === 'ios'
          ? `ios-information-circle${focused ? '' : '-outline'}`
          : 'md-home'
      }
    />
  ),
}

HomeStack.path = ''

const SearchStack = createStackNavigator({
    Search: SearchScreen
  },
  config
)

SearchStack.navigationOptions = {
  tabBarLabel: 'Search',
  showLabel: false,
  tabBarIcon: ({ focused }) => (
    <TabBarIcon focused={focused} name={`${Platform.OS === 'ios' ? 'ios' : 'md'}-search`} />
  )
}

SearchStack.path = ''

const UploadStack = createStackNavigator({
    Upload: UploadScreen,
  },
  config
)

UploadStack.navigationOptions = {
  tabBarLabel: 'Upload',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon focused={focused} name={Platform.OS === 'ios' ? 'ios-link' : 'md-cloud-upload'} />
  ),
}

UploadStack.path = '';

const ProfileStack = createStackNavigator({
    Profile: ProfileScreen,
  },
  config
)

ProfileStack.navigationOptions = {
  tabBarLabel: 'Profile',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon focused={focused} name={Platform.OS === 'ios' ? 'ios-options' : 'md-person'} />
  )
}

ProfileStack.path = ''

const tabNavigator = createBottomTabNavigator({
  HomeStack,
  SearchStack,
  UploadStack,
  ProfileStack,
}, {
  tabBarOptions: {
    showLabel: false
  }
})

tabNavigator.path = ''

export default tabNavigator
