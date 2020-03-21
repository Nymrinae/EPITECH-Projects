FROM node:12.7-alpine

WORKDIR /app
COPY ./client /app
COPY ./mobile/apk/client.apk /app/src/static/client.apk
RUN npm install

EXPOSE 8081

CMD npm run dev