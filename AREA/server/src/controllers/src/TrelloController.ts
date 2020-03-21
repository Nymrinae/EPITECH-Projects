import { Request, Response } from 'express'
import RequestController from './RequestController'
import * as Trello from 'trello'

const trello = new Trello("231fb09dee1cae67dfab34bff634aced", "3df577db9f07ff5e2c9089df7f0964c1662a3e83914420643955b2f0984a2931");

export default class TrelloController extends RequestController {
  // GET
  public async getBoardActions(req: Request, res: Response): Promise<Response> {
    try {
      const { id } = req.params

      if (!id) {
        return super.sendMissingFieldsError(res)
      }

      const board = await trello.getActionsOnBoard(id)

      return super.sendSuccess(res, board)
    }catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }


  public async getBoardByID(req: Request, res: Response): Promise<Response> {
    try {
      const { id } = req.body

      if (!id)
        return super.sendMissingFieldsError(res)

      const board = await trello.getBoard(id)

      return super.sendSuccess(res, board)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }


  public async getCardByID(req: Request, res: Response): Promise<Response> {
    try {
      const { id } = req.body

      if (!id)
        return super.sendMissingFieldsError(res)

      const card = await trello.getCard(id)

      return super.sendSuccess(res, card)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }
  // POST
  public async postCard(req: Request, res: Response): Promise<Response> {
    try {
      const { idList } = req.body

      if (!idList)
        return super.sendMissingFieldsError(res)

      const card = await trello.addCard(idList)

      return super.sendSuccess(res, card)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }
  
  // PUT
  public async updateCardByID(req: Request, res: Response): Promise<Response> {
    try {
      const { id, field, value } = req.body

      if (!id || !field || !value)
        return super.sendMissingFieldsError(res)

      const card = await trello.updateCard(id, field, value)

      return super.sendSuccess(res, card)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  // DELETE
  public async deleteCardByID(req: Request, res: Response): Promise<Response> {
    try {
      const { id } = req.body

      if (!id )
        return super.sendMissingFieldsError(res)

      const card = await trello.deleteCard(id)

      return super.sendSuccess(res, card)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }
}