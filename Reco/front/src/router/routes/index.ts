const routes = [
  {
    path: '/',
    name: 'app-type',
    component: () => import('@/views/AppType.vue'),
    meta: {
      layout: 'full'
    }
  },
  {
    path: '/dataset',
    name: 'dataset-stats',
    component: () => import('@/views/DatasetStats.vue'),
    meta: {
      pageTitle: 'Dataset Stats',
      breadcrumb: [
        { text: 'Dataset', active: false }
      ]
    }
  },
  {
    path: '/client/:id',
    name: 'client-stats',
    component: () => import('@/views/ClientStats.vue'),
    meta: {
      pageTitle: 'Client {} Stats',
      breadcrumb: [
        { text: 'Client', active: false }
      ]
    }
  },
  {
    path: '*',
    redirect: '/'
  }
]

export default routes