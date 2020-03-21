<template>
  <v-card
    color="#FF4500"
    class="ml-3 mr-12 pb-8"
    dark
    max-width="400"
  >
    <v-card-title>
      <v-icon large left> mdi-reddit </v-icon>
      <h3>Reddit</h3>
    </v-card-title>
    <v-flex class="searchbar">
      <v-row align="center" justify="center">
        <v-radio-group v-model="reqType" row>
          <v-radio label="New" value="new" color="orange darken-2"></v-radio>
          <v-radio label="Hot" value="hot" color="orange darken-2"></v-radio>
          <v-radio label="Top" value="top" color="orange darken-2"></v-radio>
          <v-radio label="Rising" value="rising" color="orange darken-2"></v-radio>
        </v-radio-group>
        <v-btn icon @click="searchOnReddit">
          <v-icon> mdi-magnify </v-icon>
        </v-btn>
      </v-row>
    </v-flex>
    <div v-if="posts.length">
      <v-container class="areaInfo text-center container">
        <v-row
          v-for="item in posts"
          :key="item"
        >
          <v-col cols="6">
            <a :href="item.url" target="blank">
              <v-img
                width="150"
                height="100"
                :src="item.thumbnail"
              />
            </a>
          </v-col>
          <v-col cols="6">
            <h5 class="text"> {{ item.title }} </h5>
            <h6 class="text"> {{ item.author }} </h6>
          </v-col>
        </v-row>
      </v-container>
    </div>
  </v-card>
</template>

<script>
import { mapGetters } from 'vuex'
import { getRedditPosts } from '../../../api/services'

export default {
  data() {
    return {
      show: false,
      reqType: 'new',
      msg: '',
      type: 'info',
      posts: []
    }
  },
  async mounted() {
    await this.searchOnReddit()
  },
  methods: {
    ...mapGetters({
      subreddit: 'user/getSubreddit'
    }),
    async searchOnReddit() {
      try {
        const req = await getRedditPosts(this.subreddit(), this.reqType)
        const latestsPosts = []

        for (const post of req.data.children.slice(0, 5)) {
          const item = {
            author: post.data.author,
            title: post.data.title,
            thumbnail: post.data.thumbnail === 'self'
              ? 'https://via.placeholder.com/200.png?text=No+Thumbnail'
              : post.data.thumbnail,
            url: `https://www.reddit.com${post.data.permalink}`
          }
          latestsPosts.push(item)
        }
        this.posts = latestsPosts
      } catch (e) {
        console.log(e)
      }
    }
  }
}
</script>

<style>
.text {
  padding-top: 15px;
  padding-right: 10px;
  text-align: justify;
}
</style>
