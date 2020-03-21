import * as express from 'express'
import { EpitechIntraController } from '../../controllers'

export default class AuthRoutes {
  public epitechIntraController: EpitechIntraController = new EpitechIntraController()

  public routes(router: express.Router): void {
    router.get('/intra/profile', this.epitechIntraController.getUserProfile)

    router.get('/intra', this.epitechIntraController.getGeneralUserInfo)

    router.post('/intra/register', this.epitechIntraController.register)

    router.get('intra/notif', this.epitechIntraController.getNotificationMessage)

    router.get('intra/notif/coming', this.epitechIntraController.getNotificationUpcoming)

    /*router.get('user/notification/alert', this.epitechIntraController.getNotificationAlert)

    router.get('user/notification/missed', this.epitechIntraController.getNotificationMissed)

    router.get('user/:login/notes', this.epitechIntraController.getUserGrades)

    router.get('user/:login/binome', this.epitechIntraController.getUserBinome)

    router.get('user/:login/', this.epitechIntraController.getUserProfil)

    router.get('user/:login/netsoul', this.epitechIntraController.getUserNetsoul)

    router.get('user/:login', this.epitechIntraController.getUser)

    router.get('/module/:year/:module/:instance/:activity/project/', this.epitechIntraController.getProject)

    router.get('/module/:year/:module/:instance/:activity/file/', this.epitechIntraController.getProjectFiles)

    router.get('/module/:year/:module/:instance/:activity/rdv/', this.epitechIntraController.getProjectRDV) */
  }
}