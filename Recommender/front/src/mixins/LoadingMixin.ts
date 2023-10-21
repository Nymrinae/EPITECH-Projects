import { Component, Vue } from 'vue-property-decorator'
import { GraphModule } from '@/store/modules'

@Component({
  components: {
    Loading: () => import('@/components/Loading.vue')
  }
})
export default class LoadingMixin extends Vue {
  @GraphModule.State tabLoading
  @GraphModule.Mutation updateTabLoadingState
}
