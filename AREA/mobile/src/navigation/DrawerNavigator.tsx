import React from 'react';
import { createDrawerNavigator } from '@react-navigation/drawer'
import { NavigationContainer, DefaultTheme, DarkTheme } from '@react-navigation/native';
import DrawerContent from '../components/DrawerContent'
import StackNavigator from './StackNavigator'
import { useTheme } from 'react-native-paper';
const Drawer = createDrawerNavigator()

const DrawerNavigator = () => {
  const theme = useTheme();
  const navigationTheme = theme.dark ? DarkTheme : DefaultTheme;

  return (
    <NavigationContainer theme={navigationTheme}>
      <Drawer.Navigator drawerContent={props => <DrawerContent {...props} />}>
        <Drawer.Screen name="Home" component={StackNavigator} />
      </Drawer.Navigator>
    </NavigationContainer>
  );
}

export default DrawerNavigator