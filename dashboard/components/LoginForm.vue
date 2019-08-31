<template>
  <v-card flat>
    <SocialAuthentication 
      header="Log In with"
      type="Log In" />
    <v-form
      ref="form"
      class="form"
      v-model="valid"
      lazy-validation 
    >
      <p class="title"> or </p>
      <v-text-field v-model="name" prepend-icon="mdi-account" label="Username" solo required />
      <v-text-field 
        v-model="password"
        :type="isPasswordVisible ? 'text' : 'password'"
        prepend-icon="mdi-textbox-password"
        :append-icon="isPasswordVisible ? 'mdi-eye' : 'mdi-eye-off'"
        label="Password"
        @click:append="isPasswordVisible = !isPasswordVisible"
        solo required
        />
      <v-card-actions class="justify-center">
        <v-btn block :disabled="!valid" color="success" class="button" @click="emailLogin"> 
          Log In
          <v-icon class="icon" dark>mdi-login</v-icon>
        </v-btn>
      </v-card-actions>
    </v-form>
  </v-card>
</template>

<script> 
import { mapActions } from 'vuex'
import SocialAuthentication from '@/components/SocialAuthentication'

export default {
  data() {
    return {
      isPasswordVisible: false,
      valid: true,
      name: '',
      email: '',
      password: '',
    }
  },
  components: {
    SocialAuthentication
  },
  methods: {
    ...mapActions({
      emailLogin: ''
    }),
    async emailLogin() {
      if (this.$refs.form.validate()) {
        this.emailLogin(this.email, this.password);
        this.email = ''
        this.password = ''
      }
    },
    reset () {
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