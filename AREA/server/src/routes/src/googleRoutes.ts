import * as express from 'express'
import * as mailer from 'nodemailer'
import { GoogleController } from '../../controllers'

export default class GoogleRoutes {
  public googleController: GoogleController = new GoogleController()

  public routes(router: express.Router): void {
    router.post('/mail/send', this.googleController.sendMail)
  }
}