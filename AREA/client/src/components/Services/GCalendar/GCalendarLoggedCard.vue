<template>
  <v-card
    color="#26c6da"
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
            Tweet !
          </v-btn>
        </v-row>
      </v-list-item>
    </v-card-actions>
  </v-card>
</template>

<script>
import { mapGetters } from 'vuex'
import axiosInstance from '../../../api/axiosConfig'

export default {
  data: () => ({
    content: '',
    errorMsg: ''
  }),
  computed: {
    // avatar() { return this.twitterCreds().photoURL },
    // username() { return this.twitterCreds().username }
  },
  methods: {
    ...mapGetters({
      // hasDiscordWebhook: 'user/getDiscordWebhookState',
      // discordWebhook: 'user/getDiscordWebhookLink',
      // // isLoggedOnFacebook: 'auth/getFacebookAuthState',
      // facebookCreds: 'auth/getFacebookCreds',
      // twitterCreds: 'auth/getTwitterCreds'
      googleCreds: 'auth/getGoogleCreds'
    }),
    async tweet() {
      /* if (this.onFacebook) {
        if (!this.isLoggedOnFacebook()) {
          this.errorMsg = 'You must log on Facebook before !'

          return false
        }

        await axiosInstance.post('/postonwall', {
          accessToken: this.facebookCreds().accessToken,
          message: this.content
        })
      } */
      console.log(this.content)
      const res = await axiosInstance.get(`${this.content}/events`, {
        headers: {
          accessToken: this.googleCreds().accessToken,
          secret: this.googleCreds().secret
        }
      })
      console.log(res)
      // if (this.hasDiscordWebhook()) {
      //   const webhookid = this.discordWebhook().split('/')[5]
      //   const webhooktoken = this.discordWebhook().split('/')[6]

      //   await axiosInstance.post('/discordmsg', { content: this.content }, {
      //     headers: {
      //       webhookid,
      //       webhooktoken
      //     }
      //   })
      // }

      // await axiosInstance.post('/tweet', { content: this.content }, {
      //   headers: {
      //     accessToken: this.twitterCreds().accessToken,
      //     secret: this.twitterCreds().secret
      //   }
      // })
    }
  }
}
</script>
