import * as firebase from 'firebase'

const firebaseConfig = {
  apiKey: 'AIzaSyCXd3WGUEACHfPr2h9jLmX5eRnTc_2K6aE',
  authDomain: 'area-epitech-f2987.firebaseapp.com',
  databaseURL: 'https://area-epitech-f2987.firebaseio.com/',
  projectId: 'area-epitech-f2987',
  storageBucket: 'area-epitech-f2987.appspot.com',
  messagingSenderId: '1068043205958',
  appId: '1:1068043205958:web:ff7e151adb3a2a6d15b947',
  measurementId: 'G-RNJLRDZG1F'
}

!firebase.apps.length
  ? firebase.initializeApp(firebaseConfig)
  : firebase.app()

export const auth = firebase.auth()
export const TwitterProvider = new firebase.auth.TwitterAuthProvider