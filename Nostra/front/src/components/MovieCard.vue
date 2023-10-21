<script setup lang="ts">
const props = defineProps({
  movie: {
    type: Object,
    required: true,
    default: null,
  },
})
</script>

<template>
  <div class="p-2 lg:w-1/4 md:w-1/2 w-full">
    <div class="h-full flex items-center border-gray-800 border p-4 rounded-lg hover:border-blue-100 hover:cursor-pointer">
      <div class="flex-grow">
        <h2 class="text-white title-font font-medium">{{ movie.title }} ({{movie.date_published.split('-')[0] }})</h2>
        <p class="text-gray-600">{{ movie.writer }}</p>
      </div>
    </div>
  </div>
</template>

<style>
</style>