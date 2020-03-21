<template>
  <v-card
    color="#4682B4"
    dark
    max-width="600px"
  >
    <v-card-title>
      <v-img
        class="text-center mr-1"
        src="https://pngimage.net/wp-content/uploads/2018/06/logo-epitech-png-4.png"
        max-height="40"
        max-width="40"
        contain
      />
      <span
        class="title font-weight-medium"
        style="color: black"
      >
        Register to activities
      </span>
    </v-card-title>

    <v-tabs
      v-model="tab"
      background-color="transparent"
      color="basil"
      grow
    >
      <v-tab
        v-for="item in items"
        :key="item"
      >
        {{ item.name }}
      </v-tab>
    </v-tabs>
    <v-tabs-items v-model="tab">
      <v-tab-item
        v-for="(item, i) in items"
        :key="i"
        style="background-color: #212121"
      >
        <div v-if="getItems(item.id).length != 0">
          <IntraActivity
            v-for="(project, a) in getItems(item.id)"
            :key="a"
            :title="project.title"
            :module="project.module"
            :start="project.timeline_start"
            :end="project.timeline_end"
            :register="project.register_link"
            :moduleregister="project.title_link"
            :isproject="project.soutenance_date != undefined"
          />
        </div>
        <IntraNotFound v-else />
      </v-tab-item>
    </v-tabs-items>
  </v-card>
</template>

<script>
import { mapGetters } from 'vuex'
import axiosInstance from '../../../api/axiosConfig'
import IntraActivity from './IntraActivity'
import IntraNotFound from './IntraNotFound'

export default {
  components: {
    IntraActivity,
    IntraNotFound
  },
  data: () => ({
    tab: null,
    items: [
      { id: 'projects', name: 'projects' },
      { id: 'activities', name: 'activities' },
      { id: 'modules', name: 'modules' }
    ],
    projects: [],
    activities: [],
    modules: []
  }),
  async mounted() {
    try {
      const res = await axiosInstance.get('/intra', {
        headers: {
          token: this.token()
        }
      })
      const { projets, activites, modules } = res.data.board

      this.projects = projets
      this.activities = activites
      this.modules = modules
    } catch (e) {
      console.log(e)
    }
  },
  methods: {
    ...mapGetters({
      token: 'auth/getIntraToken'
    }),
    getItems(id) {
      switch (id) {
        case 'projects':
          return this.projects
        case 'activities':
          return this.activities
        case 'modules':
          return this.modules
      }
    }
  }
}
</script>
