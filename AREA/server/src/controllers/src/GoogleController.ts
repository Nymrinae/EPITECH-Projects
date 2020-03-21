import { Request, Response } from 'express'
import * as mailer from 'nodemailer'
import RequestController from './RequestController'

export default class GoogleController extends RequestController {
  public async sendMail(req: Request, res: Response): Promise<any> {
    const { mailAddress, mailTitle, mailContent } = req.body
    console.log(req.body)
  
    try {
      const mail = {
        from: "areaepitechxd@gmail.com",
        to: mailAddress,
        subject: mailTitle,
        html: mailContent
      }

      const smtpTransport = mailer.createTransport({
        service: 'gmail',
        auth: {
          user: 'areaepitechxd@gmail.com',
          pass: 'epitecharea1'
        }
      })

      smtpTransport.sendMail(mail, (err, res) => {
        if (err)
          console.log(err)
        
        console.log('Successfully sent')
      })

      return res.status(200)
    } catch(e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }
}