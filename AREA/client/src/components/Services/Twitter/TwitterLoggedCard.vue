<template>
  <v-card
    color="#26c6da"
    class="ml-3 mr-3 pb-8"
    dark
    max-width="400"
  >
    <v-card-title>
      <v-icon large left> mdi-twitter </v-icon>
      <span
        class="title font-weight-medium"
        style="color: black"
      >
        Post a tweet
      </span>
    </v-card-title>

    <v-textarea
      v-model="content"
      class="headline font-weight-bold ml-3 mr-3"
      counter="280"
      auto-grow
      clearable
      outlined
      filled
    />
    <v-switch
      v-model="onFacebook"
      label="Post also on Discord (need to configure Webhook first) ?"
      class="ml-4"
    />
    <!-- <p
      v-if="!isLoggedOnFacebook()"
      class="subtitle-1 text-center"
      style="color: red"
    >
      {{ errorMsg }}
    </p> -->

    <v-card-actions>
      <v-list-item class="grow">
        <v-list-item-avatar color="grey darken-3">
          <v-img
            class="elevation-6"
            :src="avatar"
          ></v-img>
        </v-list-item-avatar>

        <v-list-item-content>
          <v-list-item-title
            class="subtitle-1 font-weight-medium"
            style="color: black"
          >
            {{ username }}
          </v-list-item-title>
        </v-list-item-content>

        <v-row
          align="center"
          justify="end"
        >
          <v-btn
            @click="tweet"
          >
            Tweet ! {{ message }}
          </v-btn>
        </v-row>
      </v-list-item>
    </v-card-actions>
  </v-card>
</template>

<script>
import { mapGetters } from 'vuex'
import io from 'socket.io-client'
/* eslint-disable */
import {
  getRetweet,
  listeningToTwitter,
  postOnDiscord,
  postOnTwitter
} from '../../../api/services'

export default {
  data: () => ({
    content: '',
    errorMsg: '',
    onFacebook: false,
    message: '',
    socket: io('localhost:8080')
  }),
  computed: {
    avatar() { return this.twitterCreds().photoURL },
    username() { return this.twitterCreds().username }
  },
  async created() {
    await listeningToTwitter(this.twitterCreds())
    this.socket.on('message', (data) => alert(data))
  },
  mounted() {
    this.socket.on('message', data => console.log(data))
  },
  methods: {
    ...mapGetters({
      hasDiscordWebhook: 'user/getDiscordWebhookState',
      discordWebhook: 'user/getDiscordWebhookLink',
      twitterCreds: 'auth/getTwitterCreds'
    }),
    async tweet() {
      if (this.hasDiscordWebhook()) {
        const data = {
          action: 'New tweet posted on Twitter !',
          content: this.content,
          from: 'twitter'
        }
        await postOnDiscord(this.discordWebhook(), data)
      }

      await postOnTwitter(this.twitterCreds(), this.content)
    },
    async retweet() {
      const res = await getReTweet(this.twitterCreds())

      console.log(res)
    }
  }
}
</script>
