<template>
  <v-container fill-height fluid>
    <v-layout justify-center wrap>
      <Sidebar />
      <v-flex xs12 md4 style="padding-left:300px; margin-right: 50px; margin-top: 100px">
        <Card
          v-if="userFinishedLoading"
          class="v-card-profile"
          :style="addMargin()"
        >
          <v-avatar
            slot="offset"
            class="mx-auto d-block"
            size="150"
          >
            <img :src="user.photoURL">
          </v-avatar>
          <v-card-text class="text-xs-center">
            <div>
              <h4> Username :</h4>
              <p> {{ user.name }} </p>
            </div>
            <div>
              <h4> Email :</h4>
              <p> {{ user.email }} </p>
            </div>
            <div>
              <h4> Registered to :</h4>
              <v-chip
                v-for="service in userServices"
                :key="service"
                close
                :close-icon="addIcon(service, 'delete')"
                style="margin: 10px 5px 0px 0px"
                @click:close="deleteService(service)"
              >
                {{ firstLetterUppercase(service) }}
              </v-chip>
            </div>
          </v-card-text>
        </Card>
      </v-flex>
      <v-flex xs12 md6 style="margin-top: 50px;">
        <Card
          v-if="userFinishedLoading"
          v-model="card"
          color="white"
          title="Update your informations!"
          text="Any changes can be done here"
          elevation="5"
        >
          <v-form>
            <v-container py-0>
              <v-layout wrap>
                <v-flex xs12 md6>
                  <v-text-field
                    v-model="newUsername"
                    label="Update your username"
                    class="space"
                  />
                </v-flex>
                <v-flex xs12 md6>
                  <v-text-field
                    v-model="newEmail"
                    label="Update your email"
                    class="space"
                  />
                </v-flex>
                <v-flex xs12 md6>
                  <v-text-field
                    v-model="newPassword"
                    label="Update your password"
                    type="password"
                    class="space"
                  />
                </v-flex>
                <v-flex xs12 md6>
                  <v-text-field
                    v-model="newPP"
                    label="Enter file URL"
                    class="space"
                  />
                </v-flex>
                <v-row align="center" justify="center">
                  <v-btn
                    class="mx-0 font-weight-light"
                    style="margin: 50px 50px 20px 20px"
                    dark
                    @click="changeInformations"
                  >
                    Update infos
                  </v-btn>
                </v-row>
              </v-layout>
            </v-container>
          </v-form>
        </Card>
        <Card
          v-if="userFinishedLoading"
          v-model="card"
          color="white"
          title="Register to services!"
          text="Register to services here and use them in your homepage!"
          elevation="5"
        >
          <v-row align="center" justify="center">
            <h3 style="margin-bottom: 25px;">
              Available services
            </h3>
          </v-row>
          <v-row align="center" justify="center">
            <v-chip
              v-for="(availableService, key) in availableServices"
              :key="key"
              close
              :close-icon="addIcon(availableService, 'add')"
              style="margin: 10px 5px 50px 0px"
              @click:close="addService(availableService)"
            >
              {{ firstLetterUppercase(availableService) }}
            </v-chip>
          </v-row>
        </Card>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
import {
  db,
  auth
} from '@/plugins/firebase'
import Card from '@/components/Dashboard/Card'
import Sidebar from '@/components/Dashboard/Sidebar'

export default {
  components: {
    Card,
    Sidebar
  },
  data() {
    return {
      user: null,
      card: true,
      newUsername: null,
      newEmail: null,
      newPassword: null,
      newPP: null,
      successMsg: false,
      userFinishedLoading: false,
      userServices: [],
      availableServices: []
    }
  },
  computed: {
    storedUser() {
      return this.$store.getters['fireAuth/getCurrentUser']
    },
    authUser() {
      return auth.currentUser
    }
  },
  mounted() {
    this.getUserServices()
    this.getAvailableServices()
  },
  methods: {
    async changeInformations() {
      const user = auth.currentUser
      console.log(user.photoURL)
      // const storageRef = storage.ref(user + '/profilePicture' + this.newPP.name)
      const ref = db.collection('users').doc(this.storedUser.uid)
      const snap = await ref.get()

      await ref.update({
        name: this.newUsername ? this.newUsername : snap.data().name,
        email: this.newEmail ? this.newEmail : snap.data().email,
        photoURL: this.newPP ? this.newPP : snap.data().photoURL
      })
      if (this.newEmail) {
        await user.updateEmail(this.newEmail)
      }
      if (this.newPassword) {
        await user.updatePassword(this.newPassword)
      }
      if (this.newPP) {
        await user.updateProfile({
          photoURL: this.newPP
        })
      }

      alert('Successfully updated!')
    },
    async getAvailableServices() {
      const availableServices = await this.$axios.$get('/about.json')
      let services = []

      for (const service of availableServices.server.services) {
        services.push(service.name)
      }
      services = services.filter((e) => {
        return !this.serviceCantBeUpdated(e)
      })
      this.availableServices = services
    },
    isRegistered() {
      return null
    },
    async addService(service) {
      const newServices = this.user.services
      if (!newServices.includes(service)) {
        newServices.push(service)
      } else {
        this.err = 'You\'re already registe red to this service!'
      }
      const ref = db.collection('users').doc(this.storedUser.uid)

      await ref.update({ services: newServices })
      this.userServices = newServices
      this.availableServices = this.availableServices.filter((e) => {
        return e !== service
      })
      console.log(newServices)
    },
    async deleteService(service) {
      const updatedServices = this.user.services.filter((e) => {
        return e !== service
      })
      const ref = db.collection('users').doc(this.storedUser.uid)
      await ref.update({ services: updatedServices })
      this.userServices = updatedServices
      this.user.services = updatedServices
      this.availableServices.push(service)
    },
    async getUserServices() {
      const ref = db.collection('users').doc(this.storedUser.uid)
      const snap = await ref.get()
      const data = snap.data()

      const user = {
        name: data.name,
        email: data.email,
        photoURL: this.storedUser.photoURL,
        services: data.services
      }

      this.user = user
      this.userServices = user.services
      this.userFinishedLoading = true
    },
    addIcon(service, action) {
      if (this.serviceCantBeUpdated(service)) {
        return ''
      }
      return `mdi-${action === 'add' ? 'plus-thick' : 'trash-can-outline'}`
    },
    serviceCantBeUpdated(service) {
      return service === 'weather' || service === 'stockExchange'
    },
    submit() {
      alert(this.email)
    },
    addMargin() {
      return this.$vuetify.breakpoint.name !== 'xs' ? 'margin-top: 125px' : ''
    },
    firstLetterUppercase(str) {
      return str.replace(/^./, str[0].toUpperCase())
    }
  }
}
</script>

<style scoped>
.space {
  margin-left: 25px;
  margin-right: 25px;
}
</style>
