FROM node:12.7-alpine

ENV APP_ROOT /src

RUN mkdir ${APP_ROOT}
WORKDIR ${APP_ROOT}
COPY package*.json ./

RUN npm install
COPY . .
RUN npm run build
  
EXPOSE 8080

ENTRYPOINT [ "npm", "run", "start"]