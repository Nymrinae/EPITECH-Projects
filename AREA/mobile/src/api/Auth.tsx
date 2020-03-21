import axiosInstance from '../api/axiosConfig'
import { User } from '../types'
import { auth } from '../api/firebase'

const login = async (user: User) => {
  try {
    const res = auth.signInWithEmailAndPassword(user.email, user.password)

    return res

  } catch(e) {
    throw e
  }
}

const facebookLogin = async () => {
  try {
    const res = await axiosInstance.get('/users/login/facebook')

    console.log(res)

    return res 
  } catch(e) {
    throw e
  }
}

const googleLogin = async () => {
  try {
    const res = await axiosInstance.get('/users/login/google')

    console.log(res)

    return res
  } catch(e) {
    throw e
  }
}

const register = async (user: User) => {
  try {
    const res = await axiosInstance.post('/users/register', {
      avatar: user.avatar,
      username: user.username,
      email: user.email,
      password: user.password
    })

    console.log(res)

    return res
  } catch(e) {
    console.log(e)
    throw e
  }
}

const logout = async () =>  {
  try {
    const res = await axiosInstance.post('/users/logout')

    return res
  } catch(e) {
    throw e
  }
}

export {
  facebookLogin,
  googleLogin,
  login,
  logout,
  register
}