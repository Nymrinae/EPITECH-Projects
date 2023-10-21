<template>
  <div>
    <h4 class="mb-1"> Ticket Stats </h4>
    <v-select
      v-model="selectedMonth"
      class="mb-2"
      :options="ticketMonthsOnly"
      label="title"
    >
      <template #option="{ title }">
        <span> {{ title }}</span>
      </template>
    </v-select>
    <b-card no-body>
    <h6 class="text-center"> A total of {{ totalTicketAmount }} tickets on {{ selectedMonth.title }}. </h6>
    </b-card>
    <b-row>
      <b-col
        v-for="ticket in selectedTickets"
        :key="ticket.ticket_id"
        cols="3"
      >
        <TicketCard :ticketId="ticket.ticket_id" />
      </b-col>
    </b-row>
  </div>
</template>

<script lang="ts">
import { Client } from '@/api'
import { Component, Vue, Watch } from 'vue-property-decorator'
import { GraphModule } from '@/store/modules'
import vSelect from 'vue-select'

@Component({
  components: {
    TicketCard: () => import('@/components/Ticket/TicketCard.vue'),
    vSelect
  }
})
export default class ClientGeneralStats extends Vue {
  @GraphModule.State months
  @GraphModule.Mutation setMonth

  allTickets = []
  selectedTickets = []
  selectedMonth: any[] = []
  ticketMonthsOnly = []

  @Watch('selectedMonth')
  onMonthChange(month) {
    this.updateTicketSelection(month.value)
  }

  async mounted() {
    const { tickets } = await Client.getClientTickets(this.$route.params.id)
    const monthsTickets = [...new Set(tickets.map(e => parseInt(e.month)))]

    this.allTickets = tickets
    this.ticketMonthsOnly = this.months.filter(e => monthsTickets.includes(e.value))
    this.selectedMonth = this.ticketMonthsOnly[0]
  }

  get totalTicketAmount() {
    return this.selectedTickets.length
  }

  updateTicketSelection(monthValue) {
    this.selectedTickets = this.allTickets.filter(e => (e as any).month == monthValue)
    console.log(this.selectedTickets)
  }
}
</script>