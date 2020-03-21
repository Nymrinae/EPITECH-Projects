import axiosInstance from '../api/axiosConfig'

const getCurrentUser = async () => {
  try {
    const res = await axiosInstance.get('/user')

    return res.data
  } catch (e) {
    throw e
  }
}

export {
  getCurrentUser
}