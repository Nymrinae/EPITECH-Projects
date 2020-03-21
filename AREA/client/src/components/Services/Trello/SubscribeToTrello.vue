<template>
  <v-dialog v-model="dialog" max-width="600px">
    <template v-slot:activator="{on}">
      <v-list>
        <v-list-item
          class="mt-n1"
          v-on="on"
        >
          <v-list-item-action>
            <v-icon> mdi-trello </v-icon>
          </v-list-item-action>
          <v-list-item-title
            class="grey--text text--darken-1"
          >
            Subscribe to a Trello
          </v-list-item-title>
        </v-list-item>
      </v-list>
    </template>
    <v-card>
      <v-card-title>
        <span class="headline text-center"> Subscribe to a trello </span>
      </v-card-title>
      <v-card-text>
        Get a notification whenever something is posted on this Trello!
      </v-card-text>
      <v-card-text v-if="errorMsg">
        Webhook incorrect
      </v-card-text>
      <v-text-field
        v-model="trello"
        class="ml-6 mr-6 mt-n3"
        label="Enter your Trello name here"
      />
      <v-card-actions class="pb-6 pr-6">
        <v-spacer />
        <v-btn @click="addTrello">
          Add
        </v-btn>
      </v-card-actions>
    </v-card>
    <v-snackbar
      v-model="snackbar"
      :timeout="2000"
      top
      color="green"
    >
      Successfully added !
    </v-snackbar>
  </v-dialog>
</template>

<script>
import { mapActions, mapGetters } from 'vuex'
import axiosInstance from '../../../api/axiosConfig'
import { postOnDiscord, sendEmail } from '../../../api/services'
import { db } from '../../../api/firebase'

export default {
  data: () => ({
    trello: '',
    date: '',
    dialog: false,
    snackbar: false,
    errorMsg: false
  }),
  mounted() {
    window.setInterval(() => {
      this.triggerTrello()
    }, 10000)
  },
  methods: {
    ...mapActions({
      setTrello: 'user/setTrello'
    }),
    ...mapGetters({
      email: 'auth/getEmail',
      discordWebhook: 'user/getDiscordWebhookLink',
      hasDiscordWebhook: 'user/getDiscordWebhookState'
    }),
    async addTrello() {
      try {
        if (this.trello) {
          const res = await axiosInstance.get(`/b/${this.trello}/actions`)
          db.collection('trello').doc(this.email()).collection('dates').doc(this.trello).set({
            date: res.data[0].date
          })
          // db.collection('trello').doc(this.email()).set({
          //   [this.trello]: db.collection('trello').doc(this.email()).collection('dates').doc(this.trello).get()
          // })

          const mailInfos = {
            mailAddress: 'lacaillepaul@gmail.com',
            mailTitle: 'AREA Notification',
            mailContent: '<p> You have successfully subscribed to a new Trello on AREA</p>'
          }
          if (this.hasDiscordWebhook()) {
            await postOnDiscord(this.discordWebhook(), {
              action: 'AREA notification',
              content: mailInfos.mailContent,
              from: 'AREA'
            })
          }
          await sendEmail(mailInfos)
        }
        // const res = await axiosInstance.get(`/b/${this.trello}/actions`)
        // if (res.data[0].date !== this.date) {
        //   this.date = res.data[0].date
        //   const mailInfos = {
        //     mailAddress: 'lacaillepaul@gmail.com',
        //     mailTitle: 'New trello notification',
        //     mailContent: `<p> Board : ${JSON.stringify(res.data[0].data.board.name)} \n List : ${JSON.stringify(res.data[0].data.list.name)} \n Card : ${JSON.stringify(res.data[0].data.card.name)}</p>`
        //   }
        //   if (this.hasDiscordWebhook()) {
        //     await postOnDiscord(this.discordWebhook(), {
        //       action: 'New trello notification',
        //       content: mailInfos.mailContent,
        //       from: 'trello'
        //     })
        //   }
        //   await sendEmail(mailInfos)
        // }

        // console.log(res)
      } catch (e) {
        console.log(e)
      }
    },

    async triggerTrello() {
      // const res = await axiosInstance.get('/b/BPu7YFvK/actions')

      const allTrello = await db.collection('trello').doc(this.email()).collection('dates').get()
      const documents = []
      allTrello.forEach((doc) => {
        documents.push(doc.id)
      })
      console.log(documents)

      for (let i = 0; i < documents.length; i++) {
        let mailInfos = null
        const res = await axiosInstance.get(`/b/${documents[i]}/actions`)
        await db.collection('trello').doc(this.email()).collection('dates').doc(documents[i]).get().then((date) => {
          if (res.data[0].date !== date.data().date) {
            db.collection('trello').doc(this.email()).collection('dates').doc(documents[i]).set({
              date: res.data[0].date
            })
            mailInfos = {
              mailAddress: 'lacaillepaul@gmail.com',
              mailTitle: 'New trello notification',
              mailContent: `<p> Board : ${JSON.stringify(res.data[0].data.board.name)} \n List : ${JSON.stringify(res.data[0].data.list.name)} \n Card : ${JSON.stringify(res.data[0].data.card.name)}</p>`
            }
          }
        })
        if (mailInfos) {
          if (this.hasDiscordWebhook()) {
            await postOnDiscord(this.discordWebhook(), {
              action: 'New trello notification',
              content: mailInfos.mailContent,
              from: 'trello'
            })
          }
          await sendEmail(mailInfos)
        }
      }

      // documents.forEach((item) => {
      //   db.collection('trello').doc('lacaillepaul@gmail.com').collection('dates').doc(item).get().then((date) => {
      //     const info = await axiosInstance.get(`/b/${item}/actions`)
      //     console.log(info)
      //     if (info.data[0].date !== date.data().date) {
      //       console.log('Karibou')
      //       // const mailInfos = {
      //       //   mailAddress: 'lacaillepaul@gmail.com',
      //       //   mailTitle: 'New trello notification',
      //       //   mailContent: `<p> Board : ${JSON.stringify(res.data[0].data.board.name)} \n List : ${JSON.stringify(res.data[0].data.list.name)} \n Card : ${JSON.stringify(res.data[0].data.card.name)}</p>`
      //       // }
      //       // if (this.hasDiscordWebhook()) {
      //       //   await postOnDiscord(this.discordWebhook(), {
      //       //     action: 'New trello notification',
      //       //     content: mailInfos.mailContent,
      //       //     from: 'trello'
      //       //   })
      //       // }
      //       // await sendEmail(mailInfos)
      //     } else {
      //       console.log('Kiwi')
      //     }
      //   })
      // })
      // if (res.data[0].date !== db.collection(this.email()).doc('trello').collection(this.trello).doc('info')) {
      //   this.date = res.data[0].date
      //   const mailInfos = {
      //     mailAddress: 'lacaillepaul@gmail.com',
      //     mailTitle: 'New trello notification',
      //     mailContent: `<p> Board : ${JSON.stringify(res.data[0].data.board.name)} \n List : ${JSON.stringify(res.data[0].data.list.name)} \n Card : ${JSON.stringify(res.data[0].data.card.name)}</p>`
      //   }
      //   if (this.hasDiscordWebhook()) {
      //     await postOnDiscord(this.discordWebhook(), {
      //       action: 'New trello notification',
      //       content: mailInfos.mailContent,
      //       from: 'trello'
      //     })
      //   }
      //   await sendEmail(mailInfos)
      // }

      // console.log(res)
    }
  }
}
</script>

<style>

</style>
