const path = require('path')

module.exports = {
  lintOnSave: false,
  publicPath: '/',
  css: {
    loaderOptions: {
      sass: {
        sassOptions: {
          includePaths: ['./node_modules', './src/assets'],
        },
      },
    },
  },
  configureWebpack: {
    resolve: {
      alias: {
        '@themeConfig': path.resolve(__dirname, 'src/config/themeConfig.ts')
      },
    },
    optimization: {
      concatenateModules: false,
      providedExports: false,
      usedExports: false
    },
  },
  chainWebpack: config => {
    config.module
      .rule('vue')
      .use('vue-loader')
      .loader('vue-loader')
      .tap(options => {
        // eslint-disable-next-line no-param-reassign
        options.transformAssetUrls = {
          img: 'src',
          image: 'xlink:href',
          'b-avatar': 'src',
          'b-img': 'src',
          'b-img-lazy': ['src', 'blank-src'],
          'b-card': 'img-src',
          'b-card-img': 'src',
          'b-card-img-lazy': ['src', 'blank-src'],
          'b-carousel-slide': 'img-src',
          'b-embed': 'src',
        }
        return options
      })

    config.module
      .rule('i18n-loader')
      .test(/.\.yaml$/)
      .use('json')
        .loader('json-loader')
      .end()
      .use('yaml')
        .loader('yaml-loader')
      .end()
  },
  transpileDependencies: ['vue-echarts', 'resize-detector'],
}
