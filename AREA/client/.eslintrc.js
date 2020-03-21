module.exports = {
  root: true,
  env: {
    browser: true,
    node: true
  },
  parserOptions: {
    parser: 'babel-eslint'
  },
  extends: [
    '@nuxtjs',
    'plugin:nuxt/recommended'
  ],
  // add your custom rules here
  rules: {
    'nuxt/no-cjs-in-config': 'off',
    "space-before-function-paren": ["error", {
      "anonymous": "never",
      "named": "never",
      "asyncArrow": "always"
    }],
    "vue/html-self-closing": ["error", {
      "html": {
        "void": "any",
        "normal": "any",
        "component": "any"
      },
    }],
    "vue/singleline-html-element-content-newline": ["error", {
      "ignores": ["h1", "h2", "h3", "h4", "h5", "h6", "div", "p", "v-icon", "span", "v-subheader", "v-list-item-title", "v-list-item"]
    }],
    'no-console': 'off',
    "no-unused-expressions": ["error", {"allowTernary": true}],
  }
}
