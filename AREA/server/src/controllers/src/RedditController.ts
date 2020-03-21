import { Request, Response } from 'express'
import RequestController from './RequestController'
import * as SnooStream from 'snoostream'

export default class RedditController extends RequestController {
  public async setSubreddit(req: Request, res: Response): Promise<any> {
    try {
      const snooStream = SnooStream({
        userAgent: 'web:epitecharea:v1 (by /u/Nymrinae)',
        clientId: 'ZBM70LhKUk9jOA',
        clientSecret: 'J0sf8yfM6FjFwbgv__4TS11mEQw',
        refreshToken: '21680174694-DqrKKwlYVMKm442NLlC0iakJPn0'
      })

      const submissionStream = snooStream.submissionStream(req.body.subreddit, { regex: /.*/ })
  
      submissionStream.on('post', (post: any, match: any) => {
        console.log(post)
        return res.status(200).json(post)
      })
    } catch(e) {
      console.log(e)
      super.sendErrorMessage(res, e)
    }
  }
}
