import firebase from 'firebase/app'
import 'firebase/auth'
import 'firebase/firestore'

// const firebaseConfig = {
//   apiKey: process.env.FIREBASE_APIKEY,
//   authDomain: process.env.FIREBASE_AUTHDOMAIN,
//   databaseURL: process.env.FIREBASE_DATABASE_URL,
//   projectId: process.env.FIREBASE_PROJECTID,
//   storageBucket: process.env.FIREBASE_STORAGEBUCKET,
//   messagingSenderId: process.env.FIREBASE_MESSAGINGSENDERID,
//   appId: process.env.FIREBASE_APPID,
//   measurementId: process.env.FIREBASE_MEASUREMENTID
// }

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
export const db = firebase.firestore()
export const GoogleProvider = new firebase.auth.GoogleAuthProvider()
export const TwitterProvider = new firebase.auth.TwitterAuthProvider()
export const FacebookProvider = new firebase.auth.FacebookAuthProvider()
export const GithubProvider = new firebase.auth.GithubAuthProvider()
