type Nullable<T> = T | null | undefined

class URLManager {
  buildParams(params: { [key: string]: Nullable<string> }) {
    const filteredParams = Object.entries(params).reduce((a,[k,v]) => (v ? (a[k]=v, a) : a), {})

    return new URLSearchParams(filteredParams).toString()
  }

  checkURLParams(params: string[]) {
    const urlParams = new URLSearchParams(window.location.search)
    const checkParams = {}
  
    params.forEach(e => {
      checkParams[e] = urlParams.get(e) ?? ''
    })
  
    return checkParams
  }

  updateURLParams(key: string, value?: any) {
    const url = new URL(window.location.href)
    const searchParams = url.searchParams
  
    value
      ? searchParams.set(key, value)
      : searchParams.delete(key)
  
    url.search = searchParams.toString()
    history.pushState({}, '', url.toString())
  }
}

const urlManager = new URLManager()

export default urlManager