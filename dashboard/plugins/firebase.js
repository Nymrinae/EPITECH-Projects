import * as firebase from 'firebase/app'
import 'firebase/auth'
import 'firebase/database'

const firebaseConfig = {
  apiKey: process.env.firebase.apiKey,
  authDomain: process.env.firebase.authDomain,
  databaseURL: process.env.firebase.databaseURL,
  projectId: process.env.firebase.projectId,
  storageBucket: process.env.firebase.storageBucket,
  messagingSenderId: process.env.firebase.messagingSenderId,
  appId: process.env.firebase.appId
};

!firebase.apps.length ? firebase.initializeApp(firebaseConfig) : null;

export const auth = firebase.auth()
export const db = firebase.database()
export const GoogleProvider = new firebase.auth.GoogleAuthProvider()
export const FacebookProvider = new firebase.auth.FacebookAuthProvider()

export default firebase