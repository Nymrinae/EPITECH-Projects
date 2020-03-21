import { Request, Response } from 'express'
import { 
  auth,
  db
} from '../../../config/firebaseConfig'
import RequestController from './RequestController'

export default class AuthController extends RequestController {
  public async standardLogin(req: Request, res: Response): Promise<Response> {
    try {
      const { email } = req.body

      if (!email)
        return super.sendMissingFieldsError(res)
      
      const ref = await db.collection('users').where('email', '==', email).get()
      
      if (ref) {
        const id = ref.docs[0].id
        const token = await auth.createCustomToken(id)

        return super.sendSuccess(res, token)
      }
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async standardRegister(req: Request, res: Response): Promise<Response> {
    try {
      const { avatar, username, email, password } = req.body

      if (!username || !email || !password)
        return super.sendMissingFieldsError(res)

      const user = await auth.createUser({
        email,
        password,
        displayName: username
      })

      const ref = db.collection('users').doc(user.uid)

      const userInfo = {
        displayName: username,
        photoURL: '',
        email: user.email,
        services: []
      }

      await ref.set(userInfo)

      return super.sendCreationSuccessful(res, user)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }
}