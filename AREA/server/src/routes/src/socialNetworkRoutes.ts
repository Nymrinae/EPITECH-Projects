import * as express from 'express'
import { SocialNetworkController } from '../../controllers'

export default class SocialNetworkRoutes {
  public socialNetworkController: SocialNetworkController = new SocialNetworkController()

  public routes(router: express.Router): void {
    // Discord
    router.post('/discordwebhook', this.socialNetworkController.setWebhook)
    router.post('/discordmsg', this.socialNetworkController.postDiscordMessage)

    // Twitter
    router.get('/retweet', this.socialNetworkController.retweet)
    router.post('/tweet', this.socialNetworkController.tweet)
    router.get('/twitterlistener', this.socialNetworkController.twitterListener)
  }
}