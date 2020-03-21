import axios from 'axios'
import axiosInstance from './axiosConfig'

const getRedditPosts = async (subreddit, type) => {
  const req = await axios.get(`https://www.reddit.com/r/${subreddit}/${type}.json`)

  return req.data
}
const getRetweet = async (creds) => {
  await axiosInstance.get('/retweet', {
    headers: {
      accessToken: creds.accessToken,
      secret: creds.secret
    }
  })
}

const listeningToTwitter = async (creds) => {
  await axiosInstance.get('/twitterlistener', {
    headers: {
      accessToken: creds.accessToken,
      secret: creds.secret
    }
  })
}

const postOnDiscord = async (webhook, data) => {
  const webhookid = webhook.split('/')[5]
  const webhooktoken = webhook.split('/')[6]

  await axiosInstance.post('/discordmsg', data, {
    headers: {
      webhookid,
      webhooktoken
    }
  })
}

const postOnTwitter = async (creds, content) => {
  await axiosInstance.post('/tweet', { content }, {
    headers: {
      accessToken: creds.accessToken,
      secret: creds.secret
    }
  })
}

const registerToIntraModule = async (token, url) => {
  const res = await axiosInstance.post('/intra/register', { token, url })

  return res
}

const sendEmail = async (mailInfos) => {
  await axiosInstance.post('/mail/send', mailInfos)
}

export {
  getRetweet,
  getRedditPosts,
  listeningToTwitter,
  postOnDiscord,
  postOnTwitter,
  registerToIntraModule,
  sendEmail
}
