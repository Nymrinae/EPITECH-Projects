import { unAuthedInstance, authedInstance } from './axiosConfig'

module.exports = {
  getGalleries: async (section, sort) => {
      let res = await unAuthedInstance.get(`/3/gallery/${section}/${sort}`)
      res = res.data.data
      let data = []

      for (image of res) {
        let imageData = {
          author: image.account_url,
          desc: image.images ? image.images[0].description : image.description,
          link: image.images ? image.images[0].link : image.link,
          title: image.title,
          points: image.points
        }
        data.push(imageData)
      }

      let newData = data.filter(e => {
        return !['mp4', 'gif'].includes(e.link.slice(-3))
      })

      return newData
  },
  getImages: async (type, value) => {
    try {
      let images = []
      let res = type ? await unAuthedInstance.get(`/3/gallery/t/${value}`)
                      : await unAuthedInstance.get(`/3/gallery/search?q=${value}`)

      res = type ? res.data.data.items : res.data.data
      res = res.slice(0, 15)

      for (elem of res) {
        const isFileTypeCorrect = (elem) => {
          return (
            elem.is_album && !elem.images[0].type.slice(-3) === 'gif' ||
            !(['mp4', 'gif'].includes(elem.link.slice(-3))))
        }

        if (isFileTypeCorrect(elem)) {
          let image = {
            id: elem.is_album ? elem.images[0].link.split('/')[3].slice(0, 7) : elem.id,
            author: elem.account_url ? elem.account_url : 'Anonym',
            desc: elem.is_album ? elem.images[0].description : elem.description,
            title: elem.title,
            link: elem.is_album ? elem.images[0].link : elem.link,
            views: elem.views
          }
          images.push(image)
        } else {
          continue
        }
      }

      return images
    } catch(e) {
      return false
    }
  },
  getImageFromGallery: async (galleryHash) => {
    try {
      let res = await unAuthedInstance.get(`/3/gallery/image/${galleryHash}`)

      return res.data.data
    } catch (e) {
      throw e
    }
  },
  getImageFromGalleryAlbum: async (hash) => {
    try {
      let res = await unAuthedInstance.get(`/3/gallery/album/${hash}`)

      return res.data.data
    } catch (e) {
      throw e
    }
  }
}