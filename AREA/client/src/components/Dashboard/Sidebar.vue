<template>
  <v-container>
    <v-navigation-drawer
      v-model="drawer"
      app
      clipped
    >
      <v-list dense>
        <!-- <v-list-item
          v-for="(item, i) in items"
          :key="i"
        >
          <v-list-item-action>
            <v-icon>{{ `mdi-${item.icon }` }}</v-icon>
          </v-list-item-action>
          <v-list-item-content>
            <v-list-item-title>
              {{ item.text }}
            </v-list-item-title>
          </v-list-item-content>
        </v-list-item>
        <v-divider /> -->
        <v-subheader class="mt-3 ml-3 grey--text text--darken-1">AVAILABLE SERVICES</v-subheader>
        <v-list>
          <!-- <v-list-item
            v-for="(service, s) in services"
            :key="s"
            class="mt-3"
            @click="testAddService(service)"
          > -->
          <DiscordWebhook />
          <SubscribeToReddit />
          <SubscribeToTrello />
          <!-- <v-list-item>
            <v-list-item-avatar>
              <v-icon :color="service.color" v-text="service.icon" />
            </v-list-item-avatar>
            <v-list-item-title v-text="service.name"></v-list-item-title>
            <v-icon> {{ !registeredServices.includes(service.name) ? 'mdi-plus' : 'mdi-minus' }} </v-icon>
          </v-list-item> -->
        </v-list>
        <!-- <v-list v-else>
          <v-list-item-content>
            <v-list-item-title
              class="grey--text text --darken-1 subtitle-2 ml-6"
            >
              No services available.
            </v-list-item-title>
          </v-list-item-content>
        </v-list> -->
        <v-divider />
        <v-subheader class="mt-3 ml-3 grey--text text--darken-1">MY CONNECTIONS</v-subheader>
        <SocialOAuth />
        <IntraOAuth />
      </v-list>
    </v-navigation-drawer>

    <v-app-bar
      app
      clipped-left
    >
      <v-img
        class="text-center"
        :src="require('../../../assets/img/logo.png')"
        max-height="40"
        max-width="40"
        contain
        @click.stop="drawer = !drawer"
      />
      <v-toolbar-title class="ml-5">
        <span class="headline font-weight-bold">ActionREAction</span>
      </v-toolbar-title>
      <v-spacer />
      <p class="body-1 font-italic mt-4 mr-3"> Logged as</p>
      <p class="title font-weight-bold mt-3 mr-3"> {{ displayName }} </p>
      <v-avatar>
        <img
          class="text-center"
          :src="photoURL ? photoURL : `https://eu.ui-avatars.com/api/?name=${displayName}`"
          max-height="35"
          max-width="35"
        />
      </v-avatar>
    </v-app-bar>
  </v-container>
</template>

<script>
import { mapActions, mapGetters } from 'vuex'
import { IntraOAuth, SocialOAuth } from '../Auth'
import { DiscordWebhook, SubscribeToReddit, SubscribeToTrello } from '../Services'

export default {
  components: {
    DiscordWebhook,
    IntraOAuth,
    SocialOAuth,
    SubscribeToReddit,
    SubscribeToTrello
  },
  data: () => ({
    drawer: null,
    dialog: null,
    items: [
      { icon: 'home', text: 'Home' },
      { icon: 'settings', text: 'Settings' }
    ],
    services: [
      { icon: 'mdi-discord', name: 'Discord', color: 'blue' },
      { icon: 'mdi-calendar', name: 'GCalendar', color: 'red lighten-1' },
      { icon: 'mdi-reddit', name: 'Reddit', color: 'orange darken-2' },
      { icon: 'mdi-trello', name: 'Trello', color: 'orange darken-1' }
    ]
  }),
  computed: {
    uid() { return this.user().uid },
    displayName() { return this.user().displayName },
    photoURL() { return this.user().photoURL },
    registeredServices() { return this.userServices() }
  },
  async mounted() {
    await this.getUserInfo()
  },
  methods: {
    ...mapActions({
      getUserInfo: 'user/getUserInfo',
      updateUser: 'user/updateUser',
      addService: 'user/addService',
      removeService: 'user/removeService'
    }),
    ...mapGetters({
      user: 'user/getUser',
      userServices: 'user/getServices'
    }),
    async testAddService(service) {
      this.registeredServices.includes(service.name)
        ? this.removeService(service.name)
        : this.addService(service.name)

      const data = {
        uid: this.uid,
        service: service.name
      }

      await this.updateUser(data)
    }
  }
}
</script>

<style>

</style>
