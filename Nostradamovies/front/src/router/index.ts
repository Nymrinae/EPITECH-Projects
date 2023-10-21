import { createRouter, createWebHistory } from 'vue-router'

const routes = [
    {
      path: '/',
      redirect: 'movies'
    },
    {
      path: '/dataset-analysis',
      name: 'dataset-analysis',
      component: () => import('@/pages/dataset-stats.vue')
    },
    {
      path: '/movies',
      name: 'movies',
      component: () => import('@/pages/movies.vue')
    },
    {
      path: '/movies/:id',
      name: 'movies-id',
      component: () => import('@/pages/movies-id.vue')
    },
    {
      path: '/guess-movie',
      name: 'guess-movie',
      component: () => import('@/pages/guess-movie.vue')
    }
]

const router = createRouter({
    history: createWebHistory(),
    routes
})

export default router