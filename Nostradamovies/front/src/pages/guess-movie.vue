<script setup lang="ts">
import { Movies } from '@/api'

const data = reactive({
  file: null as any,
  queryFile: null as any
})

const onInputFile = async(e) => {
  data.file = e.target.files[0]
}


// TODO: Find a solution to send image to backend
const analyseMoviePoster = async() => {
  const fileReader = new FileReader()

  fileReader.readAsDataURL(data.file)
  fileReader.onload = async() => {
    data.queryFile = JSON.stringify(fileReader.result)
  }

  try {
    const formData = new FormData()

    formData.append('file', data.queryFile)

    await Movies.uploadPoster(formData)
  } catch(e) {
    console.error('Cannot send file to server', e)
  }
}

const removeFile = () => {
  data.file = null
}
</script>

<template>
  <LayoutDefault>
    <section class="h-full text-gray-400 bg-gray-900 body-font">
      <div class="container px-5 pt-12 pb-4 mx-auto">
        <div class="flex flex-col text-center w-full mb-12">
        <h1 class="sm:text-3xl text-2xl font-medium title-font mb-4 text-white">Guess the genre of a movie</h1>
        </div>
        <div class="px-12 lg:px-64">
          <label for="uploadImage">
            <div class="h-96 flex align-middle justify-center border border-dashed cursor-pointer rounded">
              <div class="flex justify-center mt-44">
                {{ data.file ? `Selected file: ${data.file.name}` : 'Choose a file' }}
              </div>
            </div>
          </label>
          <input
            id="uploadImage"
            type="file"
            name="image"
            accept="image/*"
            class="hidden"
            @change="onInputFile"
          />
          <div class="flex justify-center mt-8">
            <a
              class="relative inline-flex items-center px-4 py-2 mr-4 border border-gray-300 text-md font-medium rounded-md text-white bg-gray-900 hover:bg-gray-800 cursor-pointer"
              @click="analyseMoviePoster"
            >
              Analyse movie poster
            </a>
            <a
              class="relative inline-flex items-center px-4 py-2 border border-gray-300 text-md font-medium rounded-md text-white bg-gray-900 hover:bg-gray-800 cursor-pointer"
              @click="removeFile"
            >
              Remove file
            </a>
          </div>
        </div>
      </div>
    </section>
  </LayoutDefault>
</template>