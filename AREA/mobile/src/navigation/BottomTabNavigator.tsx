import React from 'react'
import { createMaterialBottomTabNavigator } from '@react-navigation/material-bottom-tabs'

import { HomeScreen, MessagesScreen, SettingsScreen } from '../screens'

const Tab = createMaterialBottomTabNavigator();

const BottomTabs = (props: any) => {
  return (
    <React.Fragment>
      <Tab.Navigator
        initialRouteName="Feed"
        backBehavior="initialRoute"
        shifting
        barStyle={{ backgroundColor: 'white' }}
      >
        <Tab.Screen
        name="Home"
        component={ HomeScreen }
        options={{
          tabBarIcon: 'home-account'
        }}
      />
      <Tab.Screen
        name="Messages"
        component={ MessagesScreen }
        options={{
          tabBarIcon: 'message-text-outline'
        }}
      />
      <Tab.Screen
        name="Settings"
        component={ SettingsScreen }
        options={{
          tabBarIcon: 'settings'
        }}
      />
      </Tab.Navigator>
      {/* <Portal>
        <FAB
          visible={isFocused}
          icon={icon}
          style={{
            position: 'absolute',
            bottom: safeArea.bottom + 65,
            right: 16,
          }}
          color="white"
          theme={{
            colors: {
              accent: theme.colors.primary,
            },
          }}
          onPress={() => {}}
        />
      </Portal> */}
    </React.Fragment>
  );
};

export default BottomTabs

