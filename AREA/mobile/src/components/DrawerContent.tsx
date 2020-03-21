import { MaterialCommunityIcons } from '@expo/vector-icons';
import {
  DrawerContentScrollView
} from '@react-navigation/drawer';
import React from 'react';
import { StyleSheet, TouchableOpacity, View, BackHandler } from 'react-native';
import {
  Avatar,
  Caption,
  Drawer,
  Paragraph,
  Title,
} from 'react-native-paper'
import Animated from 'react-native-reanimated'

import { getCurrentUser } from '../api/User'
import { logout } from '../api/Auth';

export default class DrawerContent extends React.Component<any, any> {
  constructor(props: any) {
    super(props)

    this.state = {
      avatar: null,
      displayName: null
    }
  }

  async componentDidMount() {
    const res = await getCurrentUser()

    if (res) {
      this.setState({
        avatar: res.photoURL,
        displayName: res.displayName
      })
    }
  }

  _handleLogout = async () => {
    const res = await logout()

    if (res) {
      BackHandler.exitApp()
    }
  }

  render() {
    return (
      <DrawerContentScrollView {...this.props}>
        <Animated.View
          //@ts-ignore
          style={[
            styles.drawerContent,
            /* {
              backgroundColor: paperTheme.colors.surface,
              transform: [{ translateX }],
            }, */
          ]}
        >
          <View style={styles.userInfoSection}>
            <TouchableOpacity
              style={{ marginLeft: 10 }}
              onPress={() => {
                this.props.navigation.toggleDrawer()
              }}
            >
              <Avatar.Image
                source={{ uri: this.state.avatar }}
                size={60}
                style={{ marginTop: 10, marginLeft: -10 }}
              />
            </TouchableOpacity>
            <Title style={styles.title}> { this.state.displayName } </Title>
            <Caption style={styles.caption}>@{this.state.displayName }</Caption>
            {/* <View style={styles.row}>
              <View style={styles.section}>
                <Paragraph style={[styles.paragraph, styles.caption]}>
                  262
                </Paragraph>
                <Caption style={styles.caption}>Following</Caption>
              </View>
              <View style={styles.section}>
                <Paragraph style={[styles.paragraph, styles.caption]}>
                  69
                </Paragraph>
                <Caption style={styles.caption}>Followers</Caption>
              </View>
            </View> */}
          </View>
          <Drawer.Section style={styles.drawerSection}>
            <Drawer.Item
              icon={({ color, size }) => (
                <MaterialCommunityIcons
                  name="account-outline"
                  color={color}
                  size={size}
                />
              )}
              label="Profile"
              onPress={() => {}}
            />
            <Drawer.Item
              icon={({ color, size }) => (
                <MaterialCommunityIcons
                  name="tune"
                  color={color}
                  size={size}
                />
              )}
              label="Settings"
              onPress={() => this.props.navigation.navigate('Settings')}
            />
            <Drawer.Item
              icon={({ color, size }) => (
                <MaterialCommunityIcons
                  name="logout"
                  color={color}
                  size={size}
                />
              )}
              label="Log out"
              onPress={ this._handleLogout }
            />
          </Drawer.Section>
        </Animated.View>
      </DrawerContentScrollView>
    )
  }
}

const styles = StyleSheet.create({
  drawerContent: {
    flex: 1,
  },
  userInfoSection: {
    paddingLeft: 20,
  },
  title: {
    marginTop: 20,
    fontWeight: 'bold',
  },
  caption: {
    fontSize: 14,
    lineHeight: 14,
  },
  row: {
    marginTop: 20,
    flexDirection: 'row',
    alignItems: 'center',
  },
  section: {
    flexDirection: 'row',
    alignItems: 'center',
    marginRight: 15,
  },
  paragraph: {
    fontWeight: 'bold',
    marginRight: 3,
  },
  drawerSection: {
    marginTop: 15,
  },
  preference: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    paddingVertical: 12,
    paddingHorizontal: 16,
  },
});
