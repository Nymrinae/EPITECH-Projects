FROM node:14 as build

ARG buildCommand

RUN npm i -g serve

# create destination directory
RUN mkdir -p /usr/src/dashboard
WORKDIR /usr/src/dashboard

COPY . /usr/src/dashboard

RUN npm install
RUN $buildCommand

FROM node:14

RUN npm i -g serve

COPY --from=build /usr/src/dashboard/dist dist

# expose 5000 on container
EXPOSE 8080

# start the app
CMD [ "serve", "-s", "dist" ]