<template>
  <v-card flat>
    <v-form
      ref="form"
      v-model="valid"
      class="form"
      lazy-validation
    >
      <p class="title">
        Sign up with email !
      </p>
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
        :append-icon="isPasswordVisible ? 'mdi-eye' : 'mdi-eye-off'"
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
        :append-icon="isPasswordConfVisible ? 'mdi-eye' : 'mdi-eye-off'"
        label="Confirm Password"
        solo
        required
        @click:append="isPasswordConfVisible = !isPasswordConfVisible"
      />
      <v-card-actions class="justify-center">
        <v-btn block :disabled="!valid" color="success" class="button" @click="validate">
          Sign Up
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

export default {
  data() {
    return {
      valid: true,
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
      passwordRules: [
        v => !!v || 'Password is required',
        v => /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/.test(v) || 'Password must contain 8 characters, at least one letter and one number'
      ],
      passwordConfRules: [
        v => v === this.password || 'Passwords does not match'
      ],
      isPasswordVisible: false,
      isPasswordConfVisible: false
    }
  },
  methods: {
    ...mapActions({
      createAccount: 'fireAuth/createAccount'
    }),
    async validate() {
      if (this.$refs.form.validate()) {
        const user = {
          email: this.email,
          password: this.password
        }
        await this.createAccount(user)
      }
    },
    reset() {
      this.$refs.form.reset()
    },
    resetValidation() {
      this.$refs.form.resetValidation()
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
