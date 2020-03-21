import { Response } from 'express'

export default class RequestController {
  public sendSuccess(res: Response, message?: any) {
    return res.status(200).send(message)
  }

  public sendCreationSuccessful(res: Response, message?: any) {
    return res.status(201).send(message)
  }

  public sendMissingFieldsError(res: Response) {
    return res.status(400).send({ message: 'Missing fields' })
  }

  public sendErrorMessage(res: Response, error: any) {
    return res.status(500).send({ message: `${error.code} ${error.message}` })
  }
}