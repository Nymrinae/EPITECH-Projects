import { Request, Response } from 'express'
import RequestController from './RequestController'
import { axiosFacebookInstance } from '../../../config/axiosConfig'

import FB from 'fb'

export default class FacebookController extends RequestController {

  public async postOnWall(req: Request, res: Response): Promise<Response> {
    try {
      const { accessToken, message } = req.body

      console.log(accessToken)

      FB.setAccessToken(accessToken)
      FB.api('me/feed', 'post', { message }, (res: any) => {
        console.log(res)
      })
      // const client = new FacebookClient(accessToken, process.env.FACEBOOK_APP_ID, process.env.FACEBOOK_APP_SECRET)

      return super.sendSuccess(res)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }
}