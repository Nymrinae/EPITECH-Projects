import * as express from 'express'
import { FacebookController } from '../../controllers'

export default class facebookRoutes {
  public facebookController: FacebookController = new FacebookController()

  public routes(router: express.Router): void {

    router.post('/postonwall', this.facebookController.postOnWall)
  }
}