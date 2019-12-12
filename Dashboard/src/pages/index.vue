<template>
  <v-app>
    <v-content>
      <v-container fluid fill-height>
        <v-layout align-center justify-center>
          <v-flex xs12 sm12 md3>
            <v-img
              src="https://cdn.discordapp.com/attachments/508438109482909696/645714099686211584/unknown.png"
              style="margin-right: 20px;"
            />
            <v-tabs color="cyan" slider-color="yellow" dark grow>
              <v-tab class="tab" ripple>
                <v-icon class="icon">
                  mdi-account-arrow-right
                </v-icon>
                Log In
              </v-tab>
              <v-tab ripple>
                <v-icon class="icon">
                  mdi-account-plus
                </v-icon>
                Sign Up
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
          </v-flex>
        </v-layout>
      </v-container>
    </v-content>
  </v-app>
</template>

<script>
import LoginForm from '@/components/Auth/LoginForm'
import RegisterForm from '@/components/Auth/RegisterForm'

export default {
  components: {
    LoginForm,
    RegisterForm
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
