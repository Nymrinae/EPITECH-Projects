<template>
  <v-card flat>
    <SocialAuthentication
      header="Log In with"
      type="Log In"
    />
    <v-form
      ref="form"
      v-model="valid"
      class="form"
      lazy-validation
    >
      <p class="title">
        or
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
  </v-card>
</template>

<script>
import { mapActions } from 'vuex'
import SocialAuthentication from './SocialAuth'

export default {
  components: {
    SocialAuthentication
  },
  data() {
    return {
      isPasswordVisible: false,
      valid: true,
      email: '',
      password: ''
    }
  },
  methods: {
    ...mapActions({
      login: 'fireAuth/standardSignIn'
    }),
    validate() {
      if (this.$refs.form.validate()) {
        const user = {
          email: this.email,
          password: this.password
        }
        this.login(user)
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
