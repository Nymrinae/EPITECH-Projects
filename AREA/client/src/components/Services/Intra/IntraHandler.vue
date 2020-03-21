<!-- eslint-disable -->
<template>
  <div >
    <IntraWidget v-if="isAuthed" />
    <IntraNotLoggedIn v-else />
  </div>
</template>

<script>
import { mapGetters } from 'vuex'
import IntraWidget from './IntraWidget'
import IntraNotLoggedIn from './IntraNotLoggedIn'

export default {
  components: {
    IntraWidget,
    IntraNotLoggedIn
  },
  data: () => ({

  }),
  computed: {
    isAuthed() { return this.getIntraToken() != null }
  },
  methods: {
    ...mapGetters({
      getIntraToken: 'auth/getIntraToken'
    })
  }
}
</script>
