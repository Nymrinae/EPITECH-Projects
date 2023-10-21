<template>
  <b-card class="card-congratulation-medal">
    <h3>{{ product.product.label }}</h3>
    <b-card-text class="font-small-4">
      is the most sold product all time.
    </b-card-text>
    <h2 class="mb-75 mt-4">
      <b-link>{{ product.count }}</b-link> units
    </h2>
    <b-img
      :src="require('@/assets/badge.svg')"
      class="congratulation-medal"
      alt="Medal Pic"
    />
  </b-card>
</template>

<script>
import { Component, Prop, Vue } from 'vue-property-decorator'
import Ripple from 'vue-ripple-directive'

@Component({
  directives: {
    Ripple
  }
})
export default class TopProduct extends Vue {
  @Prop() product
}
</script>
