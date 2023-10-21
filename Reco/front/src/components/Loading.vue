<template>
  <div>
    <b-overlay :show="true" rounded="sm" :opacity="0">
      <b-card>
        <b-card-text class="text-center mt-5">
          Data is loading...
        </b-card-text>
      </b-card>
    </b-overlay>
  </div>
</template>

<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator'

@Component
export default class Loading extends Vue {
}
</script>