import { createAppContainer, createSwitchNavigator } from 'react-navigation';
import { fadeIn } from 'react-navigation-transitions';

import MainTabNavigator from './MainTabNavigator';
import LandingScreen from '../screens/LandingScreen';
import AuthScreen from '../screens/AuthScreen';

export default createAppContainer(
  createSwitchNavigator({
    Auth: AuthScreen,
    Landing: LandingScreen,
    Main: MainTabNavigator,
  },
  {
    initialRouteName: 'Landing',
    transitionConfig: () => fadeIn(5000)
  })
);
