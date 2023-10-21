<template>
  <b-card no-body>
    <b-card-body class="text-center">
      <div class="truncate">
        <h2 class="mb-25 font-weight-bolder">
          {{ new Intl.NumberFormat('fr-FR').format(stat.value) }} <span v-if="stat.currency"> € </span>
        </h2>
        <span>{{ stat.title }}</span>
      </div>
      <!-- <b-avatar
        :variant="`light-${stat.color}`"
        size="45"
      >
        <feather-icon
          v-if="stat.icon"
          size="21"
          :icon="stat.icon"
        />
      </b-avatar> -->
    </b-card-body>
  </b-card>
</template>

<script lang="ts">
import { Component, Prop, Vue } from 'vue-property-decorator'

@Component
export default class StatHorizontalCard extends Vue {
  @Prop() stat
}
</script>
