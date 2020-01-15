import { unAuthedInstance, authedInstance } from './axiosConfig'
import { getImageFromGallery, getImageFromGalleryAlbum } from '../api/Gallery'

module.exports = {
  getUserBasicInformation: async (username) => {
    const user = await unAuthedInstance.get(`/3/account/${username}`);

    return user.data.data
  },
  getUserAlbumsCount: async (username) => {
    const albumsNb = await unAuthedInstance.get(`/3/account/${username}/albums/count`)

    return albumsNb.data.data
  },
  getUserCommentsCount: async (username) => {
     const commentsNb = await unAuthedInstance.get(`/3/account/${username}/comments/count`)

     return commentsNb.data.data
  },
  getUserImagesCount: async (username) => {
    const imageNb = await unAuthedInstance.get(`/3/account/${username}/images/count`)

    return imageNb.data.data
  },
  getUserFollowingTags: async () => {
    const tags = await authedInstance.get(`/3/g/custom`)

    return tags.data.data.tags
  },
  getAccountFavorites: async () => {
    const user = await authedInstance.get(`/3/account/me/favorites/`)
    let images = []

    for (image of user.data.data) {
      const getThisFuckingLinkFFS = async (image) => {
        let imageDetails = image.is_album && image.in_gallery
                        ? await getImageFromGalleryAlbum(image.id)
                        : await getImageFromGallery(image.id)

        return imageDetails.images ? imageDetails.images[0].link : imageDetails.link
      }

      const imageObj = {
        id: image.id,
        author: image.account_url,
        title: image.title,
        url: image.in_gallery ? await getThisFuckingLinkFFS(image) : image.link
      }
      images.push(imageObj)
    }

    return images
  },
  getAccountImages: async () => {
    let images = await authedInstance.get('/3/account/me/images')
    images = images.data.data
    let data = []

    for (image of images) {
      data.push(image.link)
    }
    return data
  },
  addImageToFavorites: async (imageId) => {
    try {
      await authedInstance.post(`/3/image/${imageId}/favorite`)
    } catch (e) {
      throw e
    }
  },
}