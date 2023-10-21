<template>
  <div>
    <h6> {{ title }} </h6>
    <b-list-group>
      <b-list-group-item
        v-for="{ key, value } in stats"
        :key="key"
      >
        <div class="d-flex justify-content-between align-items-center">
          <span> {{ formatKey(key) }} </span>
          <span> {{ formatValue(value) }} </span>
        </div>
      </b-list-group-item>
    </b-list-group>
  </div>
</template>

<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator'

@Component
export default class ClientStatsList extends Vue {
  @Prop() title
  @Prop() stats

  formatKey(key: string) {
    const toCamelCase = str => str.split('_').join(' ').replace(/([-]\w)/g, g => g[1].toUpperCase())
    const camelCase = toCamelCase(key)

    return camelCase[0].toUpperCase() + camelCase.slice(1)
  }

  formatValue(value: number) {
    return Math.round(value * 100) / 100
  }
}
</script>