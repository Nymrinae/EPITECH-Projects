import * as express from 'express'
import * as cors from 'cors'
import * as bodyParser from 'body-parser'
import * as cookieParser from 'cookie-parser'
import * as socketIo from 'socket.io'
import { createServer, Server } from 'http'
import * as about from '../config/about'

require('dotenv').config()

import {
  AuthRoutes,
  GoogleRoutes,
  UserRoutes,
  EpitechIntraRoutes,
  FacebookRoutes,
  RedditRoutes,
  SocialNetworkRoutes,
  TrelloRoutes
} from './routes'

export default class App {
  private port: number
  private io: any
  private server: Server
  public app: express.Application = express()
  public router: express.Router = express.Router()
  public authRoutes: AuthRoutes = new AuthRoutes()
  public googleRoutes: GoogleRoutes = new GoogleRoutes()
  public userRoutes: UserRoutes = new UserRoutes()
  public epitechIntraRoutes: EpitechIntraRoutes = new EpitechIntraRoutes()
  public facebookRoutes: FacebookRoutes = new FacebookRoutes()
  public socialNetworkRoutes: SocialNetworkRoutes = new SocialNetworkRoutes()
  public redditRoutes: RedditRoutes = new RedditRoutes()
  public trelloRoutes: TrelloRoutes = new TrelloRoutes()

  constructor(port: number) {
    this.port = port
    this.config()
    this.createServer()
    this.routes()
    this.setSocket()

    this.authRoutes.routes(this.router)
    this.userRoutes.routes(this.router)
    this.googleRoutes.routes(this.router)
    this.epitechIntraRoutes.routes(this.router)
    this.facebookRoutes.routes(this.router)
    this.socialNetworkRoutes.routes(this.router)
    this.redditRoutes.routes(this.router)
    this.trelloRoutes.routes(this.router)
  }

  private config(): void {
    this.app.use(cors())
    this.app.use(cookieParser())
    this.app.use(bodyParser.json())
    this.app.use(bodyParser.urlencoded({ extended: false }))
  }

  private routes(): void {
    this.router.get('/', (req: any, res: any) => {
      res.status(200).send('AREA Epitech API')
    })

    this.router.get('/about(.json)?', (req: any, res: any) => {
      res.status(200).json({
        "client": {
          "host": req.ip.substr(0, 7) == '::ffff:' ? req.ip.substr(7) : req.ip
        },
        about
      })
    })

    this.app.use('/', this.router)
  }

  private createServer(): void {
    this.server = createServer(this.app)
  }

  private setSocket(): void {
    this.io = socketIo(this.server)
    this.app.set('socketio', this.io)
  }

  public run(): void {
    const addr = process.env.ADDR || '0.0.0.0'
    const port = parseInt(process.env.PORT) || this.port
    this.server.listen(port, addr, () => console.log(`Listening on port ${port}`))
  }
}