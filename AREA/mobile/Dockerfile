FROM node:12.7-alpine

RUN apk add --update git python openssh-client bash

WORKDIR /app
COPY . /app
RUN npm install -g expo-cli
RUN npm install

COPY ./apk/client.apk /var/lib/area-volume/

# RUN expo login -u babouliin -p testepitech1
# RUN expo build:android

EXPOSE 19000 19001 19002

# CMD tail -f /dev/null
CMD npm run start