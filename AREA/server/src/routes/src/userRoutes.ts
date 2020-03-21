import * as express from 'express'
import { UserController } from '../../controllers'

export default class UserRoutes {
  public userController: UserController = new UserController()

  public routes(router: express.Router): void {
    router.post('/user', this.userController.getConnectedUser)

    router.patch('/user/update', this.userController.updateUser)

    // router.delete('/users/:id', this.userController.deleteUser)
  }
}