FROM      node:10-alpine
WORKDIR   /usr/src/app

# Node.js & NPM has already been installed with node image
# so we don't need to install them there
COPY package*.json ./

RUN npm install
COPY . .
EXPOSE 80

CMD ["node", "server.js"]

