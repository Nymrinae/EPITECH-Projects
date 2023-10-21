<template>
  <header class="text-gray-400 bg-gray-900 body-font">
    <div class="container mx-auto flex flex-wrap p-5 flex-col md:flex-row items-center">
      <a class="flex title-font font-medium items-center text-white mb-4 md:mb-0">
        <img src="@/assets/logo.png" alt="Logo" width="48px" />
        <span class="ml-3 text-xl">Nostradamovies</span>
      </a>
      <nav class="md:mr-auto md:ml-4 md:py-1 md:pl-4 md:border-l md:border-gray-700	flex flex-wrap items-center text-base justify-center">
        <a href="/movies" class="mr-5 hover:text-white">Movies</a>
        <a href="/dataset-analysis" class="mr-5 hover:text-white">Dataset Analysis</a>
        <a href="/guess-movie" class="mr-5 hover:text-white">Guess Movie</a>
      </nav>
  </div>
  </header>
</template>

<style lang="css" scoped>
a {
  cursor: pointer;
}
</style>