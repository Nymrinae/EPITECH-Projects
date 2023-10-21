<template>
  <div class="auth-wrapper auth-v1 px-2">
    <div class="auth-inner py-2">
      <b-card class="mb-0">
        <b-link class="brand-logo">
          <Logo />
        </b-link>

        <b-card-title class="text-center mb-1">
          {{ appName }}
        </b-card-title>
        <b-card-text class="text-center">
          {{ appDescription }}
        </b-card-text>

        <b-button
          variant="primary"
          block
          @click="$router.push(`/dataset`)"
        >
          View Dataset
        </b-button>

        <div class="divider my-2">
          <div class="divider-text">or</div>
        </div>

        <b-form-group label-for="Client ID" label="Client ID">
          <b-form-input
            id="clientIdInput"
            v-model="clientId"
            name="client-id-input"
            placeholder="Enter Client ID"
            autofocus
          />
        </b-form-group>
        <p v-if="clientNotFound" class="text-danger text-center"> Client not found. </p>
        <b-button
          variant="primary"
          block
          @click="searchClient"
          :disabled="!clientId"
        >
          View Client Information
        </b-button>
      </b-card>
    </div>
  </div>
</template>

<script lang="ts">
import { Component, Vue, Watch } from "vue-property-decorator"
import { Client } from '@/api'
import { themeConfig } from '@/config/themeConfig'

@Component({
  components: {
    Logo: () => import('@/components/Logo.vue')
  }
})
export default class AppType extends Vue {
  clientId = '1490281'
  clientNotFound = false
  appName = themeConfig.app.appName
  appDescription = themeConfig.app.appDescription

  @Watch('clientId')
  onClientIDChange() {
    this.clientNotFound = false
  }

  async searchClient() {
    try {
      const client = await Client.checkClient(this.clientId)

      if (!client) {
        this.clientNotFound = true
        return
      }

      this.$router.push(`/client/${this.clientId}`)
    } catch(e) {
      console.error('Client not found.', e)
    }
  }
}
</script>

<style lang="scss">
@import "@/assets/scss/vue/pages/page-auth.scss";
</style>
