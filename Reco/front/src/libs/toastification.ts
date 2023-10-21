import Vue from 'vue'
import Toast from 'vue-toastification'

// Toast Notification Component Styles
import '@/assets/scss/vue/libs/toastification.scss'

const toastOptions = {
  hideProgressBar: true,
  closeOnClick: false,
  closeButton: false,
  icon: false,
  timeout: 3000,
  transition: 'Vue-Toastification__fade',
}

Vue.use(Toast, toastOptions)
