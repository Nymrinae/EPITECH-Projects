<template>
  <b-card no-body>
    <b-card-header>
      <b-card-title>Top 10 All-Time Products</b-card-title>
    </b-card-header>

    <b-card-body>
      <div
        v-for="(productEntity, index) in products"
        :key="productEntity.product.label"
        class="d-flex justify-content-between align-items-center"
      >
        <b-media no-body class="mb-2">
          <b-media-body class="my-auto">
            <h6 class="mb-0">
              {{ productEntity.product.label }}
            </h6>
            <small>{{ formatProductFamily(productEntity.product) }}</small>
          </b-media-body>
        </b-media>
        <div class="d-flex align-items-center">
          <b-media no-body class="mb-2">
            <b-media-body class="my-auto">
              <h6 class="mb-0 text-center"> #{{ index + 1}} </h6>
              <small>{{ productEntity.count }} units sold</small>
            </b-media-body>
          </b-media>
        </div>
      </div>
    </b-card-body>
  </b-card>
</template>

<script>
import { Component, Prop, Vue } from 'vue-property-decorator'

@Component
export default class StatTopCard extends Vue {
  @Prop() products

  formatProductFamily(product) {
    const { family, mesh, universe } = product

    return `${family} > ${mesh} > ${universe}`
  }
}
</script>
