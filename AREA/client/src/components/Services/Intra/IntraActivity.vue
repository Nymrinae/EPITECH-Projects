<template>
  <v-card
    color="#4682B4"
  >
    <v-card-title class="subtitle-2 font-weight-medium">
      {{ title }}
    </v-card-title>
    <v-card-actions>
      <v-list-item class="grow">
        <v-col>
          <h3 class="subtitle-2 font-weight-medium"> {{ module }} </h3>
          <h5> {{ start }} </h5>
          <h5> {{ end }} </h5>
        </v-col>
        <v-row
          align="center"
          justify="end"
        >
          <v-btn
            v-if="!isproject"
            @click="registerToModule"
          >
            Register
          </v-btn>
        </v-row>
      </v-list-item>
    </v-card-actions>
  </v-card>
</template>

<script>
import { mapGetters } from 'vuex'
import axiosInstance from '../../../api/axiosConfig'
import { postOnDiscord, registerToIntraModule, sendEmail } from '../../../api/services'

export default {
  props: {
    title: { type: String, required: true },
    module: { type: String, required: true },
    start: { type: String, required: true },
    end: { type: String, required: true },
    register: { type: String, required: true },
    moduleregister: { type: String, required: true },
    isproject: { type: Boolean, required: true },
    lastNotif: { type: String, required: false, default: null }
  },
  methods: {
    ...mapGetters({
      email: 'auth/getEmail',
      token: 'auth/getIntraToken',
      discordWebhook: 'user/getDiscordWebhookLink',
      hasDiscordWebhook: 'user/getDiscordWebhookState'
    }),
    async registerToModule() {
      try {
        const res = await registerToIntraModule(this.token(), this.register || this.moduleregister)

        if (res) {
          const mailInfos = {
            mailAddress: this.email(),
            mailTitle: `Subscribed to ${this.title} !`,
            mailContent: `<p> You successfully subscribed to the project ${this.title}. Don't forget deadlines! </p>`
          }

          if (this.hasDiscordWebhook()) {
            await postOnDiscord(this.discordWebhook(), {
              action: 'New Intra subscription!',
              content: mailInfos.mailContent.split(' ').slice(1, -1).join(' '),
              from: 'intra'
            })
          }

          await sendEmail(mailInfos)
        }
      } catch (e) {
        console.log(e)
      }
    },

    // TRY TRIGGER
    async triggerNotification() {
      try {
        const json = await axiosInstance.get('user/notification/message', {})

        if (!this.lastNotif || this.lastNotif !== json[0].id) {
          this.lastNotif = json[0].id
          const mailInfos = {
            mailAddress: this.email(),
            mailTitle: 'New Intra Notification',
            mailContent: `<p> You received a new intranet notification : \n ${json[0].title}</p>`
          }

          await sendEmail(mailInfos)
        }
      } catch (e) {
        console.log(e)
      }
    }
  }
}
</script>
