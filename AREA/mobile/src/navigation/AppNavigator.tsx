import * as React from 'react'
import { createAppContainer, createSwitchNavigator } from 'react-navigation'
import LandingScreen from '../screens/LandingScreen'
import RegisterScreen from '../screens/RegisterScreen'
import RootNavigator from './RootNavigator'

export default createAppContainer(
  createSwitchNavigator({
    Landing: { screen: LandingScreen },
    Register: { screen: RegisterScreen },
    Main: RootNavigator
  })
)
