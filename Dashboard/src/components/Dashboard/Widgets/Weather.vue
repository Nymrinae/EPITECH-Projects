<template>
  <v-card max-width="500" style="margin: 0 50px 100px 50px;">
    <v-card-title primary-title class="justify-center">
      <v-avatar style="margin-right: 5px;">
        <img src="http://icons.iconarchive.com/icons/papirus-team/papirus-apps/256/weather-icon.png">
      </v-avatar>
      <h3>Weather</h3>
    </v-card-title>
    <v-flex class="searchbar">
      <v-text-field
        v-model="city"
        solo
        label="Search a city..."
        :append-icon="`mdi-${minimumOneCity ? 'plus-thick' : 'magnify'}`"
        @click:append="search(city)"
      />
    </v-flex>
    <div v-if="actualWeather != null">
      <v-switch
        v-model="temp"
        style="float: right; margin-right: 10px;"
        label="°F"
      />
      <v-container class="text-center">
        <v-col cols="12">
          <v-row
            align="center"
            justify="center"
            class="grey lighten-5"
          >
            <div
              v-for="weather in weathers"
              :key="weather"
              style="margin: 0px 25px;"
            >
              <div :style="{ 'addMargin': oneCity }">
                <h4> {{ weather.name }} </h4>
                <h5> {{ weather.country }} </h5>
                <h5> {{ weather.localTime }} </h5>
              </div>
              <v-avatar style="margin: 10px 0 10px 0;">
                <img :src="weather.icon">
              </v-avatar>
              <h5> {{ weather.desc }} </h5>
              <h3> {{ convertWeather(weather.temp) }} </h3>
            </div>
          </v-row>
        </v-col>
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
      temp: false,
      msg: '',
      type: '',
      city: null,
      show: false,
      actualWeather: null,
      weathers: []
    }
  },
  computed: {
    oneCity() {
      return this.weathers.length === 1
    },
    minimumOneCity() {
      return this.weathers.length > 1
    }
  },
  methods: {
    async search(city) {
      try {
        this.show = true
        this.msg = ''
        const cityWeather = await this.$axios.$get(`${process.env.WEATHER_BASE_URL}?access_key=${process.env.WEATHER_APIKEY}&query=${city}`)

        if (cityWeather.error) {
          this.show = false
          this.type = 'error'
          this.msg = 'City Not Found'
        } else {
          this.show = false
          this.type = 'info'
          this.city = ''
          this.actualWeather = {
            name: cityWeather.location.name,
            icon: cityWeather.current.weather_icons[0],
            desc: cityWeather.current.weather_descriptions[0],
            temp: cityWeather.current.temperature,
            country: cityWeather.location.country,
            localTime: cityWeather.location.localtime.split(' ')[1]
          }
          this.weathers.push(this.actualWeather)
        }
      } catch (e) {
        throw e
      }
    },
    convertWeather(currentTemp) {
      return this.temp ? (currentTemp * 9 / 5) + 32 + '°F' : currentTemp + '°C'
    }
  }
}
</script>

<style scoped lang="scss">
  .searchbar {
    margin: 0 10px -5px 10px;
  }
  .addMargin {
    margin-left: 60px;
  }
</style>
