<template>
  <v-card flat>
    <!--  <SocialAuth /> -->
    <v-form
      ref="form"
      v-model="valid"
      class="form"
      lazy-validation
    >
      <p class="title mt-8 mb-8">
        Login
      </p>
      <v-text-field v-model="email" prepend-icon="mdi-account" label="Email" solo required />
      <v-text-field
        v-model="password"
        :type="isPasswordVisible ? 'text' : 'password'"
        prepend-icon="mdi-textbox-password"
        :append-icon="isPasswordVisible ? 'mdi-eye' : 'mdi-eye-off'"
        label="Password"
        solo
        required
        @click:append="isPasswordVisible = !isPasswordVisible"
      />
      <v-card-actions class="justify-center">
        <v-btn block :disabled="!valid" color="success" class="button" @click="validate">
          Log In
          <v-icon class="icon" dark>
            mdi-login
          </v-icon>
        </v-btn>
      </v-card-actions>
    </v-form>
    <v-snackbar
      v-model="snackbar"
      color="red"
      :timeout="2000"
      top
    >
      {{ errorMsg }}
      <v-btn
        icon
        dark
        @click="snackbar = false"
      >
        <v-icon> mdi-close </v-icon>
      </v-btn>
    </v-snackbar>
  </v-card>
</template>

<script>
import { mapActions } from 'vuex'
// import SocialAuth from './SocialAuth'

export default {
  components: {
    // SocialAuth
  },
  data() {
    return {
      isPasswordVisible: false,
      valid: true,
      email: 'sylvain.nymrinae@gmail.com',
      password: 'testepitech1',
      snackbar: false,
      errorMsg: ''
    }
  },
  methods: {
    ...mapActions({
      login: 'auth/login'
    }),
    async validate() {
      if (this.$refs.form.validate()) {
        const user = {
          email: this.email,
          password: this.password
        }
        const res = await this.login(user)

        if (res) {
          this.$router.replace({ path: '/dashboard' })
        } else {
          this.snackbar = true
          this.errorMsg = 'Incorrect credentials'
        }
      }
    },
    reset() {
      this.$refs.form.reset()
    }
  }
}
</script>

<style scoped>
.form {
  padding: 5px 50px 50px 50px;
}
.button {
  margin-top: 10px;
}
.icon {
  padding-left: 5px;
}
.title {
  padding-top: 10px;
  text-align: center;
}
</style>
