import axios from '@/config/axios'
import { AxiosResponse } from 'axios'

const makeGetRequest = async (path: string): Promise<AxiosResponse | any> => {
  try {
    const { data } = await axios.get(path)

    return data
  } catch (e: any) {
    return false
  }
}

export {
  makeGetRequest
}