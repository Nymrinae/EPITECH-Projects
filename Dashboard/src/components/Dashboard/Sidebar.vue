<template>
<!-- eslint-disable -->
  <v-navigation-drawer
    id="app-drawer"
    app
    dark
    floating
    persistent
    mobile-break-point="991"
    width="275"
    v-if="userFinishedLoading"
  >
    <v-layout tag="v-list" column>
      <v-list-item style="margin: 25px 0 25px 0;">
        <v-list-item-avatar>
          <img :src="user.photoURL" />
        </v-list-item-avatar>
        <v-list-item-title class="title">
          {{ user.name }}
        </v-list-item-title>
      </v-list-item>
      <v-divider />
      <v-list-item
        v-for="(link, i) in links"
        :key="i"
        :to="link.to"
        style="padding: 10px 0 10px 20px"
      >
        <v-list-item-action>
          <v-icon>{{ link.icon }}</v-icon>
        </v-list-item-action>
        <v-list-item-title v-text="link.text" />
      </v-list-item>
    </v-layout>
  </v-navigation-drawer>
</template>

<script>
import { db } from '@/plugins/firebase'

export default {
  layout: 'user',
  data: () => ({
    logo: 'https://newsroom.ionis-group.com/wp-content/uploads/2018/12/epitech-logo-quadri-baseline-anglais.png',
    user: null,
    userFinishedLoading: false,
    window: {
      height: 0,
      width: 0
    }
  }),
  computed: {
    storedUser() {
      return this.$store.getters['fireAuth/getCurrentUser']
    },
    links() {
      return [
        { to: '/dashboard', icon: 'mdi-home', text: 'Home' },
        { to: '/settings', icon: 'mdi-settings', text: 'Settings' },
        { to: '/', icon: 'mdi-logout', text: 'Logout' }
      ]
    }
  },
  mounted() {
    this.getUserInfo()
  },
  methods: {
    async getUserInfo() {
      const ref = db.collection('users').doc(this.storedUser.uid)
      const snap = await ref.get()
      const data = snap.data()

      const user = {
        name: data.name.split('@')[0],
        photoURL: this.storedUser.photoURL
      }

      this.user = user
      this.userFinishedLoading = true
    }
  }
}
</script>

<style lang="scss">
.title {
  padding-top: 5px;
}
.logo {
  height: 10px;
  padding-left: 20px;
  margin-bottom: 50px;
}

.smallLogo {
  height: 120px;
  margin-bottom: 30px;
  padding-top: 30px;
  padding-left: 50px;
}

#app-drawer {
  .v-list__tile {
    border-radius: 4px;

    &--buy {
      margin-top: auto;
      margin-bottom: 17px;
    }

    &__title {
      color: #fff;
    }
  }

  .v-image__image--contain {
    top: 9px;
    height: 60%;
  }

  .search-input {
    margin-bottom: 30px !important;
    padding-left: 15px;
    padding-right: 15px;
  }

  div.v-responsive.v-image > div.v-responsive__content {
    overflow-y: auto;
  }
}
a {
  outline: 0;
}
a:hover {
  color: inherit;
  text-decoration: none;
}
</style>
