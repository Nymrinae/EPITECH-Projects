<template>
  <v-card max-width="500" style="margin: 0 50px 100px 50px; padding: 0px 0px 30px 0px">
    <v-card-title primary-title class="justify-center">
      <v-avatar style="margin-right: 5px;">
        <img src="https://external-preview.redd.it/QJRqGgkUjhGSdu3vfpckrvg1UKzZOqX2BbglcLhjS70.png?auto=webp&s=c681ae9c9b5021d81b6c4e3a2830f09eff2368b5">
      </v-avatar>
      <h3>Reddit</h3>
    </v-card-title>
    <v-flex class="searchbar">
      <v-text-field
        v-model="subreddit"
        solo
        label="Search a subreddit..."
        append-icon="mdi-magnify"
        @click:append="getLastsPosts(subreddit)"
      />
      <v-row align="center" justify="center">
        <v-radio-group v-model="reqType" row>
          <v-radio label="New" value="new" color="orange darken-2"></v-radio>
          <v-radio label="Hot" value="hot" color="orange darken-2"></v-radio>
          <v-radio label="Top" value="top" color="orange darken-2"></v-radio>
          <v-radio label="Rising" value="rising" color="orange darken-2"></v-radio>
        </v-radio-group>
      </v-row>
    </v-flex>
    <div v-if="posts.length">
      <v-container class="areaInfo text-center container">
        <div v-for="item in posts" :key="item">
          <a :href="item.url" target="blank">
            <v-img
              width="150"
              height="100"
              style="margin: 10px 0 10px 0;"
              class="container__image"
              :src="item.thumbnail"
            />
          </a>
          <div class="container__text">
            <h5>
              {{ item.title }}
            </h5>
            <h6 style="margin-top: 10px;">
              {{ item.author }}
            </h6>
          </div>
        </div>
      </v-container>
    </div>
    <div v-else style="padding-bottom: 10px;">
      <LoadingComponent
        :msg="msg"
        :type="type"
        :show="show"
      />
    </div>
  </v-card>
</template>

<script>
import LoadingComponent from '../LoadingComponent'

export default {
  components: {
    LoadingComponent
  },
  data() {
    return {
      subreddit: '',
      show: false,
      reqType: 'new',
      msg: '',
      type: 'info',
      posts: []
    }
  },
  methods: {
    async getLastsPosts(subreddit) {
      this.show = true
      this.msg = ''

      try {
        this.show = true
        this.msg = ''

        const reqType = this.reqType
        const req = await this.$axios.$get(`${process.env.REDDIT_BASE_URL}/r/${subreddit}/${reqType}.json`)
        const latestsPosts = []

        for (const post of req.data.children.slice(0, 5)) {
          const item = {
            author: post.data.author,
            title: post.data.title,
            thumbnail: post.data.thumbnail === 'self' ? 'https://via.placeholder.com/200.png?text=No+Thumbnail' : post.data.thumbnail,
            url: `${process.env.REDDIT_BASE_URL}/${post.data.permalink}`
          }
          latestsPosts.push(item)
        }
        this.posts = latestsPosts
      } catch (e) {
        this.show = false
        this.type = 'error'
        this.msg = 'Subreddit not found'
      }
    }
  }
}
</script>

<style scoped lang="scss">
  .searchbar {
    margin: 0 10px -5px 10px;
  }
  .container {
    &__image {
      display: inline-block;
      vertical-align: top;
      width: 46%;
    }
    &__text {
      display: inline-block;
      margin-top: 25px;
      margin-left: 10px;
      width: 46%;
      @media (max-width: 620px) {
        width: 100%;
      }
    }
}
</style>
