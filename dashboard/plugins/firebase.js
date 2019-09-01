import * as firebase from 'firebase/app'
import 'firebase/auth'
import 'firebase/database'

const firebaseConfig = {
  apiKey: process.env.FIREBASE_APIKEY,
  authDomain: process.env.FIREBASE_AUTHDOMAIN,
  databaseURL: process.env.FIREBASE_DATABASEURL,
  projectId: process.env.FIREBASE_PROJECTID,
  storageBucket: process.env.FIREBASE_STORAGEBUCKET,
  messagingSenderId: process.env.FIREBASE_MESSAGINGSENDERID,
  appId: process.env.FIREBASE_APPID
};

!firebase.apps.length ? firebase.initializeApp(firebaseConfig) : null;

export const auth = firebase.auth()
export const db = firebase.database()
export const GoogleProvider = new firebase.auth.GoogleAuthProvider()
export const TwitterProvider = new firebase.auth.TwitterAuthProvider()
export const FacebookProvider = new firebase.auth.FacebookAuthProvider()

export default firebase