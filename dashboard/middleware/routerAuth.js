export default function({ store, redirect, route }) {
    const isAdminRoute = route => {
        return route.matched.some(record => record.path == '/dashboard')
    }

    store.state.user != null && route.name == '/' ? redirect('/dashboard') : ''
    store.state.user == null && isAdminRoute(route) ? redirect('/') : ''
}