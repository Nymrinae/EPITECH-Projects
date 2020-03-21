import * as express from 'express'
import { AuthController } from '../../controllers'

export default class AuthRoutes {
  public authController: AuthController = new AuthController()

  public routes(router: express.Router): void {
    router.post('/users/login', this.authController.standardLogin)

    router.post('/users/register', this.authController.standardRegister)

    /* router.get('/users/logout', this.authController.logOut) */
  }
}