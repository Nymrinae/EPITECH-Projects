import { authedInstance } from './axiosConfig'

module.exports = {
  uploadImage: async (data) => {
    let res = await authedInstance.post('/3/upload', data, { headers: {
        'Content-Type': 'multipart/form-data',
        'Accept': 'application/json'
      }
    })

    const imageInfo = {
      deleteHash: res.data.data.deleteHash,
      link: res.data.data.link
    }
    return imageInfo
  },
  deleteUploadedImage: async (id) => {
    try {
      await authedInstance.delete(`/3/image/${id}`)
    } catch (e) {
      throw e
    }
  }
}