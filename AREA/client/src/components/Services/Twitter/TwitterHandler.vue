<!-- eslint-disable -->
<template>
  <div>
    <TwitterLoggedCard v-if="isAuthed" />
    <TwitterNotLoggedCard v-else />
  </div>
</template>

<script>
import { mapGetters } from 'vuex'

import TwitterLoggedCard from './TwitterLoggedCard'
import TwitterNotLoggedCard from './TwitterNotLoggedCard'

export default {
  components: {
    TwitterLoggedCard,
    TwitterNotLoggedCard
  },
  data: () => ({

  }),
  computed: {
    isAuthed() { return this.isAuthByTwitter() }
  },
  methods: {
    ...mapGetters({
      isAuthByTwitter: 'auth/getTwitterAuthState'
    })
  }
}
</script>
