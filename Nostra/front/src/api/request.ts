import { axiosInstance as axios, imdbInstance } from '@/config/axios'

type HTTPRequest = 'GET' | 'POST'

type RequestOptions = {
  useImdbInstance: boolean
}

const request = async(httpRequest: HTTPRequest, endpoint: string, data?: any) => {
  try {
    switch(httpRequest) {
      case 'GET': {
        const { data } = await axios.get(endpoint)

        return data
      }
    }
  } catch(e) {
    console.error(e)
  }
}

const get = async(endpoint: string, options?: RequestOptions) => {
  try {
    const { data } = options?.useImdbInstance
      ? await imdbInstance.get(endpoint)
      : await axios.get(endpoint)

    return data
  } catch(e) {
    console.error(e)
  }
}

const post = async(endpoint: string, formData: any) => {
  try {
    const data = axios.post(endpoint, formData, {
      headers: {
        "Content-Type": "multipart/form-data"
      }
    })

    return data
  } catch(e) {
    console.error(e)
  }
}

export { get, post }
export default request