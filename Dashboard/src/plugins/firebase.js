import * as firebase from 'firebase/app'
import 'firebase/auth'
import 'firebase/firestore'
import 'firebase/storage'

const firebaseConfig = {
  apiKey: process.env.FIREBASE_APIKEY,
  authDomain: process.env.FIREBASE_AUTHDOMAIN,
  databaseURL: process.env.FIREBASE_DATABASEURL,
  projectId: process.env.FIREBASE_PROJECTID,
  storageBucket: process.env.FIREBASE_STORAGEBUCKET,
  messagingSenderId: process.env.FIREBASE_MESSAGINGSENDERID,
  appId: process.env.FIREBASE_APPID
}

if (!firebase.apps.length) {
  firebase.initializeApp(firebaseConfig)
}

export const auth = firebase.auth()
export const db = firebase.firestore()
export const storage = firebase.storage()
export const GoogleProvider = new firebase.auth.GoogleAuthProvider()
export const TwitterProvider = new firebase.auth.TwitterAuthProvider()
export const FacebookProvider = new firebase.auth.FacebookAuthProvider()
export const GithubProvider = new firebase.auth.GithubAuthProvider()

export default firebase
