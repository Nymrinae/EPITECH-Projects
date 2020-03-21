import * as React from 'react'
import Animated, { Easing } from 'react-native-reanimated'
import { StyleSheet, View, Button, Image, Text, Dimensions, ViewStyle, TextInput, KeyboardAvoidingView, StatusBar } from 'react-native'
import { TapGestureHandler, State } from 'react-native-gesture-handler'
import { AnimatedValue } from 'react-navigation'
import { LoginForm } from '../components'

const { width, height } = Dimensions.get('window')
const {
  Value,
  event,
  block,
  cond,
  eq,
  set,
  Clock,
  startClock,
  stopClock,
  debug,
  timing,
  clockRunning,
  interpolate,
  Extrapolate
} = Animated

function runTiming(clock: Animated.Clock, value: AnimatedValue, dest: any) {
  const state = {
    finished: new Value(0),
    position: new Value(0),
    time: new Value(0),
    frameTime: new Value(0)
  };

  const config = {
    duration: 1000,
    toValue: new Value(0),
    easing: Easing.inOut(Easing.ease)
  };

  return block([
    cond(clockRunning(clock), 0, [
      set(state.finished, 0),
      set(state.time, 0),
      set(state.position, value),
      set(state.frameTime, 0),
      set(config.toValue, dest),
      startClock(clock)
    ]),
    timing(clock, state, config),
    cond(state.finished, debug('stop clock', stopClock(clock))),
    state.position
  ]);
}

export default class LoginScreen extends React.Component<any> {
  private buttonOpacity: Animated.Value<number>
  private buttonY: Animated.Node<number>
  private onStateChange: any
  public isRegister: boolean
  public changeRegisterState: any

  constructor(props: any) {
    super(props)
    this.buttonOpacity = new Value(1)

    this.onStateChange = event([{
      nativeEvent: ({ state }) =>
        block([
          cond(
            eq(state, State.END),
            set(this.buttonOpacity, runTiming(new Clock(), 1, 0))
          )
        ])
      }
    ]);

    this.changeRegisterState = () => {
      this.setState({ isRegister: true }, () => this.onStateChange)
    }

    this.buttonY = interpolate(this.buttonOpacity, {
      inputRange: [0, 1],
      outputRange: [100, 0],
      extrapolate: Extrapolate.CLAMP
    });

    this.bgY = interpolate(this.buttonOpacity, {
      inputRange: [0, 1],
      outputRange: [-height -50, 0],
      extrapolate: Extrapolate.CLAMP
    });

    this.textInputZindex = interpolate(this.buttonOpacity, {
      inputRange: [0, 1],
      outputRange: [1, - 1],
      extrapolate: Extrapolate.CLAMP
    })

    this.textInputY = interpolate(this.buttonOpacity, {
      inputRange: [0, 1],
      outputRange: [0, 100],
      extrapolate: Extrapolate.CLAMP
    })

    this.textInputOpacity = interpolate(this.buttonOpacity, {
      inputRange: [0, 1],
      outputRange: [1, 0],
      extrapolate: Extrapolate.CLAMP
    })
  }

  render() {
    return (
      <View
        style={{
          flex: 1,
          backgroundColor: 'white',
          justifyContent: 'flex-end'
        }}
      >
        <Animated.View
          style={{
            ...StyleSheet.absoluteFill,
            transform: [{ translateY: this.bgY }]
          }}
        >
          <Image
            source={require('../../assets/bg.jpg')}
            style={{ flex: 1, height: null, width: null }}
          />
        </Animated.View>
        <View style={{ height: height / 3, justifyContent: 'center' }}>
          <TapGestureHandler onHandlerStateChange={this.onStateChange}>
            <Animated.View
              style={{
                ...styles.button,
                opacity: this.buttonOpacity,
                transform: [{ translateY: this.buttonY }]
              }}
            >
              <Text style={{ fontSize: 20, fontWeight: 'bold' }}>GETTING STARTED</Text>
            </Animated.View>
          </TapGestureHandler>
          <Animated.View
            style={{
              ...StyleSheet.absoluteFill,
              height: 12 * height / 12,
              top: null,
              justifyContent: 'center',
              backgroundColor: '#fff',
              zIndex: this.textInputZindex,
              opacity: this.textInputOpacity,
              transform: [{ translateY: this.textInputY }]
            }}
          >
            <LoginForm navigation={this.props.navigation}/>
          </Animated.View>
        </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  mainContainer: {
    flex: 1,
    backgroundColor: 'white',
    justifyContent: "flex-end"
  },
  buttonContainer: {
    ...StyleSheet.absoluteFillObject
  },
  button: {
    backgroundColor: 'white',
    height: 70,
    marginHorizontal: 20,
    borderRadius: 35,
    alignItems: 'center',
    justifyContent: 'center'
  }
})