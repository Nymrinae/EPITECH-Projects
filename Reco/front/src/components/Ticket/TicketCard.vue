<template>
  <div
    class="cursor-pointer"
    @mouseenter="showOverlay = true"
    @mouseleave="showOverlay = false"
  >
    <b-overlay
      bg-color="#101010"
      blur="1px"
      opacity="0.6"
      :rounded="true"
      :show="showOverlay"
      @click="showModal = true"
    >
      <b-card no-body class="text-center border-primary p-1">
        <div v-if="isLoading" class="truncate">
          <h6> Loading ticket info... </h6>
        </div>
        <div v-else class="truncate">
          <h6 class="mb-25 font-weight-bolder"> {{ ticketInfo.ticket_id }} </h6>
          <span>{{ formatValue(ticketInfo.total_value) }} €</span>
        </div>
      </b-card>
      <template #overlay>
        <div class="text-center">
          <h4 class="text-primary">View details</h4>
        </div>
      </template>
    </b-overlay>
    <b-modal
      v-model="showModal"
      :title="`Ticket #${ticketInfo.ticket_id}`"
      hide-footer
      centered
      size="lg"
    >
      <b-card-text>
        <b-list-group>
          <b-list-group-item
            v-for="product in ticketInfo.products"
            :key="product.label"
          >
            <div class="d-flex justify-content-between align-items-center">
              <div>
                <h6> {{ product.label }} </h6>
                <small v-if="product.family && product.mesh && product.universe">
                  {{ product.family }} > {{ product.mesh }} > {{ product.universe }}
                </small>
              </div>
              <div>
                <span> {{ formatValue(product.price) }} € </span>
              </div>
            </div>
          </b-list-group-item>
        </b-list-group>
      </b-card-text>
    </b-modal>
  </div>
</template>

<script lang="ts">
import { Ticket } from '@/api'
import { Component, Prop, Vue } from 'vue-property-decorator'

type Ticket = {
  month: number
  products: Partial<TicketProduct>[]
  ticket_id: number
  total_value: number
}

type TicketProduct = {
  family: string
  label: string
  mesh: string
  price: number
  universe: string
}

@Component
export default class TicketCard extends Vue {
  @Prop() ticketId
  ticketInfo: Ticket = {} as Ticket

  isLoading = true
  showOverlay = false
  showModal = false

  async mounted() {
    try {
      this.ticketInfo = await Ticket.getTicketInfo(this.ticketId)

      this.ticketInfo.products.push({
        label: 'TOTAL',
        price: this.ticketInfo.total_value
      })
      this.isLoading = false
      this.showOverlay = false
    } catch(e) {
      console.log(`Cannot fetch ticket #${this.ticketId}`, e)
    }
  }

  formatValue(value: number) {
    return (Math.round(value * 1000) / 1000).toFixed(2)
  }
}
</script>