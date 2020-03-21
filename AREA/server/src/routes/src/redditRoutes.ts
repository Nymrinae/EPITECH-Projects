import * as express from 'express'
import { RedditController } from '../../controllers'

export default class RedditRoutes {
  public redditController: RedditController = new RedditController()

  public routes(router: express.Router): void {
    router.post('/setsubreddit', this.redditController.setSubreddit)
  }
}