<template>
  <div class="p-4 sm:w-1/3 w-1/2 border border-gray-700 rounded">
    <h2 class="title-font font-medium text-3xl text-white">
      <slot name="title" />
    </h2>
    <p class="leading-relaxed">
      <slot name="description" />
    </p>
  </div>
</template>