<script lang="ts" setup>
  const props = defineProps({
    min: {
      type: Number,
      required: true
    },
    max: {
      type: Number,
      required: true
    },
    results: {
      type: Number,
      required: true
    },
  })
  const route = useRoute()
  const router = useRouter()

  const goToPreviousPage = () => {
    const currentPage = Number(route.query.page)

    if (currentPage <= 1) return

    router.replace({
      path: route.path,
      query: { page: currentPage - 1 }
    })
  }

  const goToNextPage = () => {
    const currentPage = Number(route.query.page)

    router.replace({
      path: route.path,
      query: { page: currentPage + 1 }
    })
  }

  const prevDisabled = computed(() => {
    return Number(route.query.page) == 1
  })

  const nextDisabled = computed(() => {
    return props.max > props.results
  })

  const getMaxResults = () => props.max > props.results ? props.results : props.max

</script>

<template>
  <section class="text-gray-400 bg-gray-900 body-font">
    <div class="container mx-auto flex flex-wrap px-5 py-10 flex-col md:flex-row items-center justify-between">
      <div class="pb-4 sm:pb-0">
        Showing {{ props.min }} to {{ getMaxResults() }} of {{ props.results }} results
      </div>
      <div class="flex-1 flex justify-between sm:justify-end">
        <a
          class="relative inline-flex items-center px-4 py-2 border border-gray-300 text-sm font-medium rounded-md text-white bg-gray-900 hover:bg-gray-800"
          :class="{ 'opacity-50 cursor-not-allowed': prevDisabled }"
          @click="goToPreviousPage"
        >
          ← Previous
        </a>
        <a
          class="ml-3 relative inline-flex items-center px-4 py-2 border border-gray-300 text-sm font-medium rounded-md text-white bg-gray-900 hover:bg-gray-800"
          :class="{ 'opacity-50 cursor-not-allowed': nextDisabled }"
          @click="goToNextPage"
        >
          Next →
        </a>
      </div>
    </div>
  </section>
</template>

<style lang="scss">
a {
  cursor: pointer;
}
</style>