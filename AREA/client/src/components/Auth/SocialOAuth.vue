<template>
  <v-list>
    <v-list-item
      v-for="(connection, c) in connections"
      :key="c"
      class="mt-3"
      @click="!isConnected(connection.name) && authWith(connection.name)"
    >
      <v-list-item-avatar>
        <v-img
          v-if="isConnected(connection.name)"
          :src="getDatas(connection.name).photoURL"
        />
        <v-icon
          v-else
          :color="connection.color"
        >
          {{ `mdi-${connection.name}` }}
        </v-icon>
      </v-list-item-avatar>
      <v-list-item-content>
        <v-list-item-title
          class="grey--text text--darken-1"
        >
          {{ isConnected(connection.name)
            ? getDatas(connection.name).displayName
            : `Connect to ${connection.name.replace(/^./, connection.name[0].toUpperCase())}`
          }}
        </v-list-item-title>
        <v-list-item-subtitle
          v-if="isConnected(connection.name) && connection.name != 'facebook'"
          class="font-italic"
          v-text="`${connection.name == 'twitter' ? '@' : ''}${getDatas(connection.name).username}`"
        />
      </v-list-item-content>
    </v-list-item>
  </v-list>
</template>

<script>
import { mapActions, mapGetters } from 'vuex'

export default {
  data: () => ({
    connections: [
      { name: 'facebook', color: 'blue darken-1' },
      { name: 'google', color: 'red darken-2' },
      { name: 'twitter', color: 'blue lighten-2' }
    ]
  }),
  methods: {
    ...mapActions({
      facebookLogin: 'auth/facebookLogin',
      googleLogin: 'auth/googleLogin',
      twitterLogin: 'auth/twitterLogin'
    }),
    ...mapGetters({
      isAuthByFacebook: 'auth/getFacebookAuthState',
      isAuthByGoogle: 'auth/getGoogleAuthState',
      isAuthByTwitter: 'auth/getTwitterAuthState',
      facebookCreds: 'auth/getFacebookCreds',
      googleCreds: 'auth/getGoogleCreds',
      twitterCreds: 'auth/getTwitterCreds'
    }),
    isConnected(name) {
      switch (name) {
        case 'facebook':
          return this.isAuthByFacebook()
        case 'google':
          return this.isAuthByGoogle()
        case 'twitter':
          return this.isAuthByTwitter()
        default:
          return null
      }
    },
    getDatas(name) {
      switch (name) {
        case 'facebook':
          return this.facebookCreds()
        case 'google':
          return this.googleCreds()
        case 'twitter':
          return this.twitterCreds()
        default:
          return null
      }
    },
    async authWith(name) {
      switch (name) {
        case 'facebook': {
          await this.facebookLogin()

          break
        }
        case 'google': {
          await this.googleLogin()

          break
        }
        case 'twitter': {
          await this.twitterLogin()

          break
        }
        default:
          break
      }
    }
  }
}
</script>

<style>

</style>
