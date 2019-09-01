const firebaseAuthErrors = code => {
    switch(code) {
        case 'auth/email-already-in-use':
            alert(`Email address is already used!`)
            break;
        case 'auth/invalid-email':
            alert(`Email address is invalid`)
            break;
        default:
            break;
    }
}

export default firebaseAuthErrors