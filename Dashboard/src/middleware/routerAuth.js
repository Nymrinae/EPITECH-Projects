export default function({ store, redirect }) {
  if (store.getters['fireAuth/getCurrentUser'] === null) {
    redirect('/')
  }
}
