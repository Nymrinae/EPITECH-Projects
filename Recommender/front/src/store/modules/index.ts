import app from './app'
import graph from './graph'

import { config } from 'vuex-module-decorators'
config.rawError = true

import { namespace } from 'vuex-class'

const AppModule = namespace('app')
const GraphModule = namespace('graph')

export {
  AppModule,
  GraphModule
}

export default {
  app,
  graph
}