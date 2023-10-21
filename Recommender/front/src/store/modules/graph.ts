import { Module, VuexModule, Mutation } from 'vuex-module-decorators'

@Module({
  namespaced: true
})
export default class GraphModule extends VuexModule {
  tabLoading = true
  currentMonth = { title: 'No month specified', value: null }
  months = [
    { title: 'No month specified', value: null },
    { title: 'January', value: 1 },
    { title: 'February', value: 2 },
    { title: 'March', value: 3 },
    { title: 'April', value: 4 },
    { title: 'May', value: 5 },
    { title: 'June', value: 6 },
    { title: 'July', value: 7 },
    { title: 'August', value: 8 },
    { title: 'September', value: 9 },
    { title: 'October', value: 10 },
    { title: 'November', value: 11 },
    { title: 'December', value: 12 }
  ]

  currentEntry = { title: 'Display all', value: -1 }
  entries = [
    { title: 'Display all', value: -1 },
    { title: '5', value: 5 },
    { title: '10', value: 10 },
    { title: '25', value: 25 },
    { title: '50', value: 50 },
  ]

  @Mutation
  updateTabLoadingState(state) {
    this.tabLoading = state
  }

  @Mutation
  setMaxEntries(entry) {
    this.currentEntry = entry
  }

  @Mutation
  setMonth(month) {
    this.currentMonth = month
  }
}