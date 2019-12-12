const firebaseAuthErrors = (code) => {
  switch (code) {
    case 'auth/email-already-in-use':
      alert(`Email address is already used!`)
      break
    case 'auth/invalid-email':
      alert(`Email address is invalid.`)
      break
    case 'auth/user-not-found':
      alert(`User not found. Please register first.`)
      break
    case 'auth/wrong-password':
      alert(`Password incorrect.`)
      break
    default:
      break
  }
}

export default firebaseAuthErrors
