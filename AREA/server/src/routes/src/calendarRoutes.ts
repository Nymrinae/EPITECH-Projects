import * as express from 'express'
import { CalendarController } from '../../controllers'

export default class CalendarRoutes {
  public CalendarController: CalendarController = new CalendarController()

  public routes(router: express.Router): void {
    // GET REQUESTS
    router.get('/calendar/:calendarId/events/:eventId', this.CalendarController.getEvent)

    router.get('/:calendarId/events/', this.CalendarController.getEventList)

    // PUT REQUESTS
    router.put('/calendar/:calendarId/events/:eventId', this.CalendarController.updateEvent)

    // POST REQUESTS
    router.post('/calendar/:calendarId/events/', this.CalendarController.postEvent)

    router.post('/calendar/:calendarId/events/watch', this.CalendarController.postEventWatch)
  }
}