<template>
  <v-dialog v-model="dialog" max-width="600px">
    <template v-slot:activator="{on}">
      <v-list>
        <v-list-item
          class="mt-n1"
          v-on="on"
        >
          <v-list-item-action>
            <v-icon> mdi-discord </v-icon>
          </v-list-item-action>
          <v-list-item-title
            class="grey--text text--darken-1"
          >
            Add a Discord Webhook
          </v-list-item-title>
        </v-list-item>
      </v-list>
    </template>
    <v-card>
      <v-card-title>
        <span class="headline text-center"> Add a Discord Webhook </span>
      </v-card-title>
      <v-card-text>
        Whenever an action is available, such as posting on Twitter, you can also post on Discord thanks to webhooks
      </v-card-text>
      <v-card-text v-if="errorMsg">
        Webhook incorrect
      </v-card-text>
      <v-text-field
        v-model="webhookLink"
        class="ml-6 mr-6 mt-n3"
        label="Paste your webhook link here"
      />
      <v-card-actions class="pb-6 pr-6">
        <v-spacer />
        <v-btn @click="addDiscordWebhook">
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

export default {
  data: () => ({
    snackbar: false,
    dialog: false,
    errorMsg: false,
    webhookLink: ''
  }),
  methods: {
    ...mapActions({
      setWebhook: 'user/setWebhook'
    }),
    ...mapGetters({
      user: 'user/getUser'
    }),
    async addDiscordWebhook() {
      /* if (!(/\bintra\b.*\bauth\b/.test(this.webhookLink))) {
        this.errorMsg = true
        return
      } */

      const data = {
        uid: this.user().uid,
        discordWebhook: this.webhookLink
      }

      await this.setWebhook(data)
      this.dialog = false
    }
  }
}
</script>

<style>

</style>
