import { Request, Response } from 'express'
import RequestController from './RequestController'
import { axiosIntraInstance } from '../../../config/axiosConfig'

export default class EpitechIntraController extends RequestController {
  public async getUserProfile(req: Request, res: Response): Promise<any> {
    try {
      const authToken = req.headers.token
      const info = await axiosIntraInstance.get(`${authToken}/user?format=json`)

      return res.status(200).json(info.data)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getGeneralUserInfo(req: Request, res: Response): Promise<any> {
    try {
      const authToken = req.headers.token
      const info = await axiosIntraInstance.get(`${authToken}/?format=json`)

      return res.status(200).json(info.data)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async register(req: Request, res: Response): Promise<any> {
    try {
      const { token, url } = req.body
      const info = await axiosIntraInstance.post(`${token}${url}register?format=json`)

      return res.status(200).json(info.data)
    } catch (e) {
      console.log(e)
      return super.sendErrorMessage(res, e)
    }
  }

  //NOTIFICATIONS REQUEST
  public async getNotificationUpcoming(req: Request, res: Response): Promise<any> {
    try {
      const authToken = req.headers.token
      const user = await axiosIntraInstance.get(`${authToken}/user/notification/coming/?format=json`)

      console.log(user)
      return res.status(200).json(user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

   public async getNotificationMessage(req: Request, res: Response): Promise<any> {
    try {

      const user = await axiosIntraInstance.get('user/notification/message/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  /*public async getNotificationAlert(req: Request, res: Response): Promise<any> {
    try {

      const user = await axiosIntraInstance.get('user/notification/alert/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getNotificationMissed(req: Request, res: Response): Promise<any> {
    try {

      const user = await axiosIntraInstance.get('user/notification/missed/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }



  // USER REQUESTS
  public async getUser(req: Request, res: Response): Promise<any> {
    try {
      const user = await axiosIntraInstance.get('user/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getUserProfil(req: Request, res: Response): Promise<any> {
    try {

      const { login } = req.body

      if (!login )
        return super.sendMissingFieldsError(res)
      const user = await axiosIntraInstance.get('user/'+login+'/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getUserGrades(req: Request, res: Response): Promise<any> {
    try {

      const { login } = req.body

      if (!login )
        return super.sendMissingFieldsError(res)
      const user = await axiosIntraInstance.get('user/'+login+'/notes/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getUserBinome(req: Request, res: Response): Promise<any> {
    try {

      const { login } = req.body

      if (!login )
        return super.sendMissingFieldsError(res)
      const user = await axiosIntraInstance.get('user/'+login+'/binome/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getUserNetsoul(req: Request, res: Response): Promise<any> {
    try {

      const { login } = req.body

      if (!login )
        return super.sendMissingFieldsError(res)
      const user = await axiosIntraInstance.get('user/'+login+'/netsoul/?format=json')

      return super.sendSuccess(res, user)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }


  //PROJECTS REQUESTS
  public async getProject(req: Request, res: Response): Promise<any> {
    try {
      const { year, module, instance, activity } = req.body

      if (!year || !module || !instance || !activity )
        return super.sendMissingFieldsError(res)

      const project = await axiosIntraInstance.get('/module/'+year+'/'+module+'/'+instance+'/'+activity+'/project/?format=json')

      return super.sendSuccess(res, project)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getProjectFiles(req: Request, res: Response): Promise<any> {
    try {
      const { year, module, instance, activity } = req.body

      if (!year || !module || !instance || !activity )
        return super.sendMissingFieldsError(res)

      const project = await axiosIntraInstance.get('/module/'+year+'/'+module+'/'+instance+'/'+activity+'/file/?format=json')

      return super.sendSuccess(res, project)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getProjectRDV(req: Request, res: Response): Promise<any> {
    try {
      const { year, module, instance, activity } = req.body

      if (!year || !module || !instance || !activity )
        return super.sendMissingFieldsError(res)

      const project = await axiosIntraInstance.get('/module/'+year+'/'+module+'/'+instance+'/'+activity+'/rdv/?format=json')

      return super.sendSuccess(res, project)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  } */

}
