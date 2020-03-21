<template>
  <v-card flat>
    <v-form
      ref="form"
      v-model="valid"
      class="form"
      lazy-validation
    >
      <p class="title"> Join us !</p>
      <v-text-field
        v-model="username"
        :rules="usernameRules"
        prepend-icon="mdi-account"
        label="Username"
        solo
        required
      />
      <v-text-field
        v-model="email"
        :rules="emailRules"
        prepend-icon="mdi-at"
        label="Email"
        solo
        required
      />
      <v-text-field
        v-model="password"
        :rules="passwordRules"
        :type="isPasswordVisible ? 'text' : 'password'"
        prepend-icon="mdi-textbox-password"
        :append-icon="`mdi-${isPasswordVisible ? 'eye' : 'eye-off'}`"
        label="Password"
        solo
        required
        @click:append="isPasswordVisible = !isPasswordVisible"
      />
      <v-text-field
        v-model="passwordConf"
        :rules="passwordConfRules"
        :type="isPasswordConfVisible ? 'text' : 'password'"
        prepend-icon="mdi-textbox-password"
        :append-icon="`mdi-${isPasswordConfVisible ? 'eye' : 'eye-off'}`"
        label="Confirm Password"
        solo
        required
        @click:append="isPasswordConfVisible = !isPasswordConfVisible"
      />
      <v-card-actions class="justify-center">
        <v-btn block :disabled="!valid" color="success" class="button" @click="validate">
          Register
          <v-icon class="icon" dark>
            mdi-login
          </v-icon>
        </v-btn>
      </v-card-actions>
    </v-form>
    <v-snackbar
      v-model="snackbar"
      color="green"
      :timeout="2000"
      top
    >
      {{ msg }}
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

export default {
  data() {
    return {
      valid: true,
      msg: '',
      snackbar: false,
      nameRules: [
        v => !!v || 'Name is required',
        v => (v && v.length <= 10) || 'Name must be less than 10 characters'
      ],
      email: '',
      emailRules: [
        v => !!v || 'E-mail is required',
        v => /.+@.+\..+/.test(v) || 'E-mail must be valid'
      ],
      password: '',
      passwordConf: '',
      isPasswordVisible: false,
      isPasswordConfVisible: false,
      passwordRules: [
        v => !!v || 'Password is required',
        v => /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/.test(v) || 'Password must contain 8 characters, at least one letter and one number'
      ],
      passwordConfRules: [
        v => v === this.password || 'Passwords does not match'
      ],
      username: '',
      usernameRules: [
        v => !!v || 'Username is required',
        v => (v && v.length > 3 && v.length < 12) || 'Username must be between 3 and 12 characters'
      ]
    }
  },
  methods: {
    ...mapActions({
      register: 'auth/register'
    }),
    async validate() {
      if (this.$refs.form.validate()) {
        const user = {
          avatar: null,
          username: this.username,
          email: this.email,
          password: this.password
        }
        const res = await this.register(user)

        if (res) {
          this.snackbar = true
          this.msg = 'Successfully registered! You can login now.'
          this.username = ''
          this.email = ''
          this.password = ''
          this.passwordConf = ''
        }
      }
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
