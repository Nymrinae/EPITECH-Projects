<!-- eslint-disable -->
<template>
  <div>
    <RedditSubscribed v-if="isSubscribed" />
    <RedditNotSubscribed v-else />
  </div>
</template>

<script>
import { mapGetters } from 'vuex'

import RedditSubscribed from './RedditSubscribed'
import RedditNotSubscribed from './RedditNotSubscribed'

export default {
  components: {
    RedditSubscribed,
    RedditNotSubscribed
  },
  computed: {
    isSubscribed() { return this.isSubscribedOnReddit().length > 0 }
  },
  methods: {
    ...mapGetters({
      isSubscribedOnReddit: 'user/getSubreddit'
    })
  }
}
</script>
