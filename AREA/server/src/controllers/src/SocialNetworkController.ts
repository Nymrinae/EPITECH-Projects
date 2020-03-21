import { Request, Response } from 'express'
import RequestController from './RequestController'

import * as Twit from 'twit'
import { Autohook } from 'twitter-autohook'
import { auth, db } from '../../../config/firebaseConfig'
import { axiosDiscordInstance } from '../../../config/axiosConfig'

export default class SocialNetworkController extends RequestController {
  static handleSocket: any
  public async setWebhook(req: Request, res: Response): Promise<Response> {
    try {
      const user = await auth.getUser(req.body.uid)
      const ref = db.collection('users').doc(user.uid)

      ref.update({
        discordWebhook: req.body.discordWebhook
      })
    
      return super.sendSuccess(res)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

  public async postDiscordMessage(req: Request, res: Response): Promise<Response> {
    const icons = {
      discord: 'https://cdn3.iconfinder.com/data/icons/popular-services-brands-vol-2/512/discord-512.png',
      intra: 'https://lh3.googleusercontent.com/sznQf6u_RQ5iGG8k2HpC7Y_kzWCSZctlLKHGsGKi66lhMICuRTQU-GfXB5IxTpbnth4',
      reddit: 'https://cdn0.iconfinder.com/data/icons/social-media-2092/100/social-36-512.png',
      twitter: 'https://iutv.univ-paris13.fr/wp-content/uploads/logo-rond-twitter.png'
    }

    try {
      const { webhookid, webhooktoken } = req.headers
      const { content, action, from } = req.body

      const data = {
        embeds: [{
          author: {
            name: 'AREA Epitech',
            icon_url: 'https://media.discordapp.net/attachments/678285549362217003/687094032999907355/logo.png'
          },
          title: action,
          description: content,
          timestamp: new Date(),
          footer: {
            text: from.replace(/^\w/, (c: string) => c.toUpperCase()),
            icon_url: icons[from]
          }
        }]
      }

      const wh = await axiosDiscordInstance.post(`/webhooks/${webhookid}/${webhooktoken}`, data)

      return super.sendSuccess(res)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

  public async tweet(req: Request, res: Response): Promise<Response> {
    try {
      const T = new Twit({
        consumer_key: process.env.TWITTER_APIKEY,
        consumer_secret: process.env.TWITTER_SECRET_KEY,
        access_token: req.headers.accesstoken as string,
        access_token_secret: req.headers.secret as string,
        timeout_ms: 60 * 1000,
        strictSSL: true
      })

      const tweet = {
        status: req.body.content
      }
      
      T.post('/statuses/update', tweet, (err, data, res) => {
        if (!err) console.log('Successfuly tweeted!')
      })

      return super.sendSuccess(res)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

  public async retweet(req: Request, res: Response): Promise<Response> {
    try {
      const T = new Twit({
        consumer_key: process.env.TWITTER_APIKEY,
        consumer_secret: process.env.TWITTER_SECRET_KEY,
        access_token: req.headers.accesstoken as string,
        access_token_secret: req.headers.secret as string,
        timeout_ms: 60 * 1000,
        strictSSL: true
      })

      // const tweet = {
      //   status: req.body.content
      // }
      
      T.get('/statuses/retweet_of_me', (err, data, res) => {
        console.log(data)
      })

      return super.sendSuccess(res)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

  public async twitterListener(req: Request, res: Response): Promise<Response> {
    try {
      const webhook = new Autohook({
        token: process.env.TWITTER_ACCESS_TOKEN,
        token_secret: process.env.TWITTER_SECRET,
        consumer_key: process.env.TWITTER_APIKEY,
        consumer_secret: process.env.TWITTER_SECRET_KEY,
        env: process.env.TWITTER_WEBHOOK_ENV
      })

      const io = req.app.get('socketio')

      await webhook.removeWebhooks()

      const events = []

      webhook.on('event', async (event: any) => {
        console.log(event)
        io.sockets.on('connection', (socket: any) => socket.emit('message', event))
      })

      await webhook.start()
      await webhook.subscribe({
        oauth_token: req.headers.accesstoken,
        oauth_token_secret: req.headers.secret
      })
    } catch(e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }
}