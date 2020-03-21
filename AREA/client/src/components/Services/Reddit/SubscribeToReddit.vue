<template>
  <v-dialog v-model="dialog" max-width="600px">
    <template v-slot:activator="{on}">
      <v-list>
        <v-list-item
          class="mt-n1"
          v-on="on"
        >
          <v-list-item-action>
            <v-icon> mdi-reddit </v-icon>
          </v-list-item-action>
          <v-list-item-title
            class="grey--text text--darken-1"
          >
            Subscribe to a subreddit
          </v-list-item-title>
        </v-list-item>
      </v-list>
    </template>
    <v-card>
      <v-card-title>
        <span class="headline text-center"> Subscribe to a subreddit </span>
      </v-card-title>
      <v-card-text>
        Get a notification whenever something is posted on this subreddit!
      </v-card-text>
      <v-card-text v-if="errorMsg">
        Webhook incorrect
      </v-card-text>
      <v-text-field
        v-model="subreddit"
        class="ml-6 mr-6 mt-n3"
        label="Enter your subreddit name here"
      />
      <v-card-actions class="pb-6 pr-6">
        <v-spacer />
        <v-btn @click="addSubreddit">
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
    subreddit: '',
    dialog: false,
    snackbar: false,
    errorMsg: false
  }),
  methods: {
    ...mapActions({
      setSubreddit: 'user/setSubreddit'
    }),
    ...mapGetters({
      user: 'user/getUser'
    }),
    addSubreddit() {
      this.setSubreddit(this.subreddit)
      this.dialog = false

      // const res = await this.setSubreddit(this.subreddit)
      // console.log(res)
    }
  }
}
</script>

<style>

</style>
