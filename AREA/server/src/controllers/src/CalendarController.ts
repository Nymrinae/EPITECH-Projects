import { Request, Response } from 'express'
import RequestController from './RequestController'
import { google } from 'googleapis'
import { axiosGCalendarInstance } from '../../../config/axiosConfig'
const calendar = google.calendar('v3')

var scopes = 'https://www.googleapis.com/auth/calendar';

export default class CalendarController extends RequestController {
  // GET REQUESTS
  public async getEvent(req: Request, res: Response): Promise<Response> {
    try {
      const { calendarId, eventId } = req.body

      if (!calendarId || !eventId )
        return super.sendMissingFieldsError(res)

      const event = await axiosGCalendarInstance.get(calendarId + '/events/' + eventId)

      return super.sendSuccess(res, event)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async getEventList(req: Request, res: Response): Promise<Response> {
    try {
      const { calendarId } = req.body

      if (!calendarId)
        return super.sendMissingFieldsError(res)

      const eventList = await axiosGCalendarInstance.get(calendarId + '/events/')

      return super.sendSuccess(res, eventList)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  // PUT REQUESTS
  public async updateEvent(req: Request, res: Response): Promise<Response> {
    try {
      const { calendarId, eventId } = req.body

      if (!calendarId || !eventId)
        return super.sendMissingFieldsError(res)

      const event = await axiosGCalendarInstance.put(calendarId + '/events/' + eventId)

      return super.sendSuccess(res, event)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  // POST REQUESTS
  public async postEvent(req: Request, res: Response): Promise<Response> {
    try {
      const { calendarId } = req.body

      if (!calendarId)
        return super.sendMissingFieldsError(res)

      const event = await axiosGCalendarInstance.post(calendarId + '/events/')

      return super.sendSuccess(res, event)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }

  public async postEventWatch(req: Request, res: Response): Promise<Response> {
    try {
      const { calendarId } = req.body

      if (!calendarId)
        return super.sendMissingFieldsError(res)

      const eventWatch = await axiosGCalendarInstance.post(calendarId + '/events/watch')

      return super.sendSuccess(res, eventWatch)
    } catch (e) {
      return super.sendErrorMessage(res, e)
    }
  }
}