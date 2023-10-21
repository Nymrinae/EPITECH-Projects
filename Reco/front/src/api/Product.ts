import { makeGetRequest } from './makeRequest'

class ProductAPI {
  async getProducts() {
    return makeGetRequest('/products')
  }

  async getTopProducts() {
    return makeGetRequest('/products/top-products')
  }

  async getProductsMonthSales(month: number) {
    return makeGetRequest(`/products/top-monthly-products/${month}`)
  }
}

const productAPI = new ProductAPI()

export default productAPI