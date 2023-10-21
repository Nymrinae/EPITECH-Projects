<template>
  <b-row
    v-if="$route.meta.breadcrumb || $route.meta.pageTitle"
    class="content-header"
  >

    <!-- Content Left -->
    <b-col
      class="content-header-left mb-2"
      cols="12"
      md="9"
    >
      <b-row class="breadcrumbs-top">
        <b-col cols="12">
          <h2 class="content-header-title float-left pr-1 mb-0">
            {{ $route.meta.pageTitle.replace('{}', `#${$route.params.id}`) }}
          </h2>
          <div class="breadcrumb-wrapper">
            <b-breadcrumb>
              <b-breadcrumb-item to="/">
                <feather-icon
                  icon="HomeIcon"
                  size="16"
                  class="align-text-top"
                />
              </b-breadcrumb-item>
              <b-breadcrumb-item
                v-for="item in $route.meta.breadcrumb"
                :key="item.text"
                :active="item.active"
                :to="item.to"
              >
                {{ item.text }}
              </b-breadcrumb-item>
            </b-breadcrumb>
          </div>
        </b-col>
      </b-row>
    </b-col>

    <b-col
      class="content-header-right text-md-right d-md-block d-none mb-1"
      md="3"
      cols="12"
    >
      <b-button
        v-ripple.400="'rgba(255, 255, 255, 0.15)'"
        variant="primary"
        class="btn-icon"
        @click="showModal = true"
      >
        <feather-icon icon="SettingsIcon" />
      </b-button>

      <b-modal
        v-model="showModal"
        id="charts-settings-modal"
        title="Graph Settings"
        ok-only
        ok-title="Save modifications"
        centered
        no-close-on-backdrop
        @ok="updateGraphSettings"
      >
        <b-card-text>
          <h5>Max entries on graphes</h5>
          <small> Set the top X entries of a stat. </small>
          <v-select
            v-model="selectedEntry"
            :options="entries"
            label="title"
          >
            <template #option="{ title }">
              <span> {{ title }}</span>
            </template>
          </v-select>
        </b-card-text>
        <b-card-text>
          <h5>Display special month</h5>
          <small> You can choose to view stats for a special month, e.g March. </small>
          <v-select
            v-model="selectedMonth"
            :options="months"
            label="title"
          >
            <template #option="{ title }">
              <span> {{ title }}</span>
            </template>
          </v-select>
        </b-card-text>
      </b-modal>
    </b-col>
  </b-row>
</template>

<script>
import { Component, Vue } from 'vue-property-decorator'
import Ripple from 'vue-ripple-directive'
import vSelect from 'vue-select'
import { GraphModule } from '@/store/modules'

@Component({
  directives: {
    Ripple,
  },
  components: {
    vSelect
  }
})
export default class AppBreadcrumb extends Vue {
  @GraphModule.State months
  @GraphModule.State currentMonth
  @GraphModule.State entries
  @GraphModule.State currentEntry
  @GraphModule.Mutation setMaxEntries
  @GraphModule.Mutation setMonth
  showModal = false

  selectedEntry = null
  selectedMonth = null

  mounted() {
    this.selectedEntry = this.currentEntry
    this.selectedMonth = this.currentMonth
  }

  updateGraphSettings(e) {
    e.preventDefault()

    this.setMaxEntries(this.selectedEntry)
    this.setMonth(this.selectedMonth)
    this.showModal = false
  }
}


</script>

<style lang="scss">
@import '@/assets/scss/vue/libs/vue-select.scss';
</style>
