<template>
  <v-dialog v-model="dialog" max-width="600px">
    <template v-slot:activator="{on}">
      <v-list>
        <v-list-item
          class="mt-n1"
          v-on="on"
        >
          <v-list-item-action>
            <v-img
              class="text-center ml-1"
              src="https://pngimage.net/wp-content/uploads/2018/06/logo-epitech-png-4.png"
              max-height="30"
              max-width="30"
              contain
            />
          </v-list-item-action>
          <v-list-item-title
            class="grey--text text--darken-1"
          >
            {{ msg }}
          </v-list-item-title>
        </v-list-item>
      </v-list>
    </template>
    <v-card>
      <v-card-title>
        <span class="headline text-center"> Connection to Epitech Intra </span>
      </v-card-title>
      <v-card-text>
        In order to login to Epitech Intra, you must provide your autologin code.
      </v-card-text>
      <v-card-text class="mt-n3">
        It can be found here : https://intra.epitech.eu/admin/autolog
      </v-card-text>
      <v-text-field
        v-model="autologinLink"
        class="ml-6 mr-6"
        label="Paste your autolog link here"
      />
      <v-card-actions class="pb-6 pr-6">
        <v-spacer />
        <v-btn @click="handleIntraLogin">
          Login
        </v-btn>
      </v-card-actions>
    </v-card>
  </v-dialog>
</template>

<script>
import { mapActions, mapGetters } from 'vuex'

export default {
  data: () => ({
    autologinLink: '',
    msg: 'Connect to Epitech Intra',
    dialog: false
  }),
  methods: {
    ...mapActions({
      intraLogin: 'auth/intraLogin'
    }),
    ...mapGetters({
      token: 'auth/getIntraToken'
    }),
    async handleIntraLogin() {
      const res = await this.intraLogin(this.autologinLink)

      if (res) {
        console.log(res.data)
        this.msg = res.data.title
        this.dialog = false
      }
    }
  }
}
</script>

<style>

</style>
