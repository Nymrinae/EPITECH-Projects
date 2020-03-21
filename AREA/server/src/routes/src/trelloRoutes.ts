import * as express from 'express'
import { TrelloController } from '../../controllers'

export default class TrelloRoutes {
  public trelloController: TrelloController = new TrelloController()

  public routes(router: express.Router): void {
    router.get('/cards/:id', this.trelloController.getCardByID)

    router.get('/board/:id', this.trelloController.getBoardByID)

    router.get('/b/:id/actions', this.trelloController.getBoardActions)
  }
}