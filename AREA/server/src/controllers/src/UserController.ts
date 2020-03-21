import { Request, Response } from 'express'
import { auth, db } from '../../../config/firebaseConfig'
import RequestController from './RequestController'

export default class UserController extends RequestController {
  public async getConnectedUser(req: Request, res: Response): Promise<Response> {
    try {
      const { idToken } = req.body

      const user = await auth.verifyIdToken(idToken)
      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async updateUser(req: Request, res: Response): Promise<Response> {
    try {
      const { uid, service } = req.body
      const ref = db.collection('users').doc(uid)
      const servicesArray = await ref.get()
      const servicesArraySnap = servicesArray.data()
      const oldServices = servicesArraySnap.services
      
      if (oldServices.includes(service)) {
        const filteredServices = oldServices.filter((e: any) => e != service)

        ref.update({
          services: filteredServices
        })
      } else {
        const newServices = [service, ...oldServices]

        ref.update({
          services: newServices
        })
      }
      
      return super.sendSuccess(res)

    } catch(e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

/*   public async deleteUser(res: Response): Promise<Response> {
    try {
      const user = auth.currentUser

      await user.delete()

      return super.sendSuccess(res)
  
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  } */
}