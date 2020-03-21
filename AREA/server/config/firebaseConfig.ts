import * as admin from 'firebase-admin'
const serviceAccount = require('./service-account-file.json')

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://area-epitech-f2987.firebaseio.com"
});

export const auth = admin.auth()
export const db = admin.firestore()