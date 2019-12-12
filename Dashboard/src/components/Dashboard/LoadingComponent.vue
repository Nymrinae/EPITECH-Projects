<template>
  <div class="text-center">
    <h3 v-if="type === 'info'" class="msg">
      {{ msg }}
    </h3>
    <h3 v-else class="err">
      {{ msg }}
    </h3>
    <v-progress-circular
      v-show="show"
      style="margin-bottom: 20px;"
      :size="32"
      color="gray"
      :indeterminate="show"
    />
  </div>
</template>

<script>
export default {
  props: {
    msg: { type: String, default: '' },
    show: { type: Boolean, default: false },
    type: { type: String, default: '' }
  }
}
</script>

<style>
.msg {
  color: blue
}
.err {
  color: rgba(194, 14, 14, 0.74);
  margin-bottom: 10px;
}
</style>
