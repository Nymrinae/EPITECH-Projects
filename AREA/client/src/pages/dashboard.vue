<template>
  <div>
    <Sidebar />
    <v-row
      class="ma-3 pa-12"
      justify="center"
    >
      <v-col cols="12">
        <v-row>
          <v-flex>
            <TwitterHandler />
          </v-flex>
          <v-flex>
            <RedditHandler />
          </v-flex>
          <v-flex>
            <IntraHandler />
          </v-flex>
        </v-row>
      </v-col>
    </v-row>
  </div>
</template>

<script>
/* eslint-disable */
import {
  GCalendarHandler,
  IntraHandler,
  RedditHandler,
  Sidebar,
  TwitterHandler
} from '../components'

export default {
  components: {
    GCalendarHandler,
    IntraHandler,
    RedditHandler,
    Sidebar,
    TwitterHandler,
  },
  data: () => ({
    lorem: 'gerogerpofjiejfoejfiorjfpoejfoezjfiezdozkekjfiezkjfoiezjfioezjoiezjfiezkj,fiozejfoierhgeriokceoziugfoezilfjhejofklekhrjof'
  })
}
</script>

<style>
</style>
