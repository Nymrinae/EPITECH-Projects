<template>
  <v-tabs
    color="cyan"
    slider-color="yellow"
    dark
    grow
  >
    <v-tab class="tab" ripple>
      <v-icon class="icon mr-4">
        mdi-account-arrow-right
      </v-icon>
      <h4> Login </h4>
    </v-tab>
    <v-tab ripple>
      <v-icon class="icon mr-4">
        mdi-account-plus
      </v-icon>
      <h4> Register </h4>
    </v-tab>
    <v-tab-item>
      <LoginForm />
    </v-tab-item>
    <v-tab-item>
      <v-card flat>
        <RegisterForm />
      </v-card>
    </v-tab-item>
  </v-tabs>
</template>

<script>
import LoginForm from './LoginForm'
import RegisterForm from './RegisterForm'

export default {
  components: {
    LoginForm,
    RegisterForm
  }
}
</script>

<style>

</style>
