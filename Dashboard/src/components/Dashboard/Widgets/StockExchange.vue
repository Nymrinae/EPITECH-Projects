<template>
  <v-card max-width="500" style="margin: 0 50px 100px 50px;">
    <v-card-title primary-title class="justify-center">
      <v-avatar style="margin-right: 5px;">
        <img src="https://static.thenounproject.com/png/398900-200.png">
      </v-avatar>
      <h3>Stock Exchange</h3>
    </v-card-title>
    <v-col cols="12">
      <v-row align="center" justify="center">
        <h3 class="justify-center">
          Currency Exchange Rate & Converter
        </h3>
      </v-row>
      <v-row align="center" justify="center">
        <v-col cols="6" md="5">
          <v-select
            v-model="c1"
            :items="currencies"
            label="Currency 1"
          />
        </v-col>
        <v-col cols="6" md="5">
          <v-select
            v-model="c2"
            :items="currencies"
            label="Currency 2"
          />
        </v-col>
        <v-col cols="6" md="2">
          <v-text-field
            v-model="value"
            label="Value"
          />
        </v-col>
      </v-row>
      <v-row align="center" justify="center">
        <v-btn
          class="align-center"
          style="margin-bottom: 20px;"
          @click="getCurrencyExchangeRate(c1, c2)"
        >
          Calculate
        </v-btn>
      </v-row>
      <v-row align="center" justify="center">
        <p v-if="err !== ''" style="color:red">
          {{ err }}
        </p>
      </v-row>
    </v-col>
    <div v-if="exchangeRate !== null && c1 && c2">
      <v-container class="text-center">
        <div>
          <h4>
            {{ `${value} ${c1} = ${c1 === c2 ? value : value * exchangeRate} ${c2}` }}
          </h4>
        </div>
      </v-container>
    </div>
  </v-card>
</template>

<script>
export default {
  data() {
    return {
      c1: null,
      c2: null,
      err: '',
      value: 1,
      exchangeRate: null,
      currencies: [
        'ADA (Cardano)',
        'AUD (Australian $)',
        'BAT',
        'BTC (BitCoin)',
        'BCH (Bitcoin Cash)',
        'CAD (Canadian $)',
        'CNH (Yuan)',
        'CHF (Swiss Franc)',
        'DOGE (DogeCoin)',
        'ETH (Ethereum)',
        'EUR (Euro)',
        'GBP (Pound)',
        'JPY (Yen)',
        'LTC (Litecoin)',
        'NEO',
        'NZD (NZ $)',
        'SEK (Krona)',
        'USD (USA $)',
        'XRP (Ripple)',
        'XLM (Stellar)'
      ]
    }
  },
  methods: {
    async getCurrencyExchangeRate(c1, c2) {
      this.err = ''
      if (!c1 || !c2) {
        this.err = 'Please select two currencies first'
        return
      }
      c1 = c1.split(' ')[0]
      c2 = c2.split(' ')[0]
      const req = await this.$axios.$get(`${process.env.SE_BASE_URL}=CURRENCY_EXCHANGE_RATE&from_currency=${c1}&to_currency=${c2}&apikey=${process.env.SE_APIKEY}`)

      this.exchangeRate = req['Realtime Currency Exchange Rate']['5. Exchange Rate']

      return req
    }
  }
}
</script>

<style scoped lang="scss">
  .searchbar {
    margin: 0 10px -5px 10px;
  }
</style>
