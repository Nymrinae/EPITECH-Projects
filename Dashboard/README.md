# DEV_dashboard_2019

### What's this project ?

#### Description

The aim of this project is to build a Dashboard with some Services and Widgets that can be customized by the user. After registering and logging in, the user have an access to his user space and thus, can modify what he wants.

#### Libraries used
  - Nuxt.js (Server-Side Rendering)
  - Vuetify
  - Vuex
  - Firebase

#### APIs Used
  - Weatherstack API
  - Reddit API
  - Poke API
  - Alpha Vantage

### Requirements
  - Docker
  - Docker Compose

### Getting Started
* Open .env.example and replace your firebase values
```sh
# FIREBASE
FIREBASE_APIKEY=
FIREBASE_AUTHDOMAIN=
FIREBASE_DATABASEURL=
FIREBASE_PROJECTID=
FIREBASE_STORAGEBUCKET=
FIREBASE_MESSAGINGSENDERID=
FIREBASE_APPID=
```
* Build and launch it w/ Docker

```sh
$ docker-compose build
$ docker-compose up
```

### Directory Structure

```sh
.
├── docs/ # documentation
    └── Widgets.md
    └── appli_structure.png
└── src/ # sources files
    └── assets/ # Non-compiled assets
    └── components/
        └── Auth/ # Auth related components
            └── LoginForm.vue
            └── RegisterForm.vue
            └── SocialAuth.vue
            └── SocialButton.vue
        └── Dashboard/ # User Dashboard related components
            └── Widgets/ # Widgets
                └── Pokemon.vue
                └── Reddit.vue
                └── StockExchange.vue
                └── Weather.vue
            └── Card.vue
            └── LoadingComponent.vue
            └── OffsetHelp.vue
            └── Sidebar.vue
    └── helpers/ # Useful functions
        └── firebaseAuthErrors.js
    └── layouts/ # Application layout
        └── default.vue
        └── error.vue
    └── middleware/ # middlewares
        └── routerAuth.vue
    └── pages/ # Vue files
        └── index.vue
        └── dashboard.vue
        └── settings.vue
    └── plugins/ # plugins 
        └── firebase.js
    └── server/
        └── index.js
    └── static/ # static assets
        └── about.json
    └── store/ # Vuex Store
        └── fireAuth.js
```