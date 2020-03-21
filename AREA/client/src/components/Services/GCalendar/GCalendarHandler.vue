<!-- eslint-disable -->
<template>
  <div>
    <GCalendarLoggedCard v-if="isAuthed" />
    <GCalendarNotLoggedCard v-else />
  </div>
</template>

<script>
import { mapGetters } from 'vuex'

import GCalendarLoggedCard from './GCalendarLoggedCard'
import GCalendarNotLoggedCard from './GCalendarNotLoggedCard'

export default {
  components: {
    GCalendarLoggedCard,
    GCalendarNotLoggedCard
  },
  data: () => ({

  }),
  computed: {
    isAuthed() { return this.isAuthByGoogle() }
  },
  methods: {
    ...mapGetters({
      isAuthByGoogle: 'auth/getGoogleAuthState'
    })
  }
}
</script>
