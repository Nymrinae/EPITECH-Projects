<template>
  <v-app>
    <v-content>
      <v-container fluid fill-height>
        <v-layout align-center justify-center>
          <v-flex xs12 sm12 md3>
            <v-tabs color="cyan" slider-color="yellow" dark grow> 
              <v-tab class="tab" ripple>
                <v-icon class="icon"> mdi-account-arrow-right </v-icon>
                Log In 
              </v-tab>
              <v-tab ripple>
                <v-icon class="icon"> mdi-account-plus </v-icon>
                 Sign Up
              </v-tab>
              <v-tab-item>
                  <!-- <SocialAuthentication header="Log In with" /> -->
                  <LoginForm />
              </v-tab-item>
              <v-tab-item>
                <v-card flat>
                  <RegisterForm />
                </v-card>
              </v-tab-item>
            </v-tabs>
          </v-flex>
        </v-layout>
      </v-container>
    </v-content>
  </v-app>
</template>

<script>
import LoginForm from '@/components/LoginForm'
import RegisterForm from '@/components/RegisterForm'
import SocialAuthentication from '@/components/SocialAuthentication'

export default {
  data() {
    return {

    }
  },
  components: {
    LoginForm,
    RegisterForm,
    SocialAuthentication
  }
}
</script>

<style scoped>
.icon {
  padding-right: 10px;
}
.tab {
  margin-left: 0px !important; /* fix v-tab issue */
}
</style>