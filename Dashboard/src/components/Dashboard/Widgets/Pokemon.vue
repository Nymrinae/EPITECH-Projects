<template>
  <v-card max-width="500" style="margin: 0 50px 100px 50px; padding: 0px 0px 30px 0px">
    <v-card-title primary-title class="justify-center">
      <v-avatar style="margin-right: 5px;">
        <img src="https://icon-library.net/images/pokemon-icon-png/pokemon-icon-png-3.jpg">
      </v-avatar>
      <h3>Pokemon</h3>
    </v-card-title>
    <v-flex class="searchbar">
      <v-text-field
        v-model="pokemon"
        solo
        label="Search a Pokemon (name or id)"
        append-icon="mdi-magnify"
        @click:append="search(pokemon)"
      />
    </v-flex>
    <div v-if="currentPokemon != null">
      <v-container class="container">
        <v-img
          width="200"
          height="200"
          style="margin: 10px 0 10px 0;"
          class="container__image"
          :src="isShiny ? currentPokemon.shiny : currentPokemon.img"
        />
        <div class="container__text">
          <h3> {{ currentPokemon.name + ' #' + parseId(currentPokemon.id) }}</h3>
          <img
            v-for="(pokemonType, i) in currentPokemon.types"
            :key="i"
            :src="pokemonType"
            style="padding: 0 5px 0 5px"
          />
          <p>
            {{ currentPokemon.desc }}
          </p>
          <v-switch
            v-model="isShiny"
            style="float: right; margin-right: 10px;"
            label="Shiny"
          />
        </div>
        <v-row align="center" justify="center">
          <h4> Evolutions </h4>
        </v-row>
        <v-col cols="12">
          <v-row
            align="center"
            justify="center"
            class="grey lighten-5"
          >
            <div
              v-for="pkmn in currentPokemon.evolutions"
              :key="pkmn"
              style="margin: 0px 25px;"
            >
              <img :src="pkmn.sprite" width="100" height="100">
              <p :style="{ 'margin': nbEvolutions }">
                {{ firstLetterUppercase(pkmn.name) }}
              </p>
            </div>
          </v-row>
        </v-col>
      </v-container>
    </div>
    <div v-else>
      <LoadingComponent
        :msg="msg"
        :type="type"
        :show="show"
      />
    </div>
  </v-card>
</template>

<script>
import LoadingComponent from '../LoadingComponent'

export default {
  components: {
    LoadingComponent
  },
  data() {
    return {
      show: false,
      msg: '',
      type: 'info',
      pokemon: null,
      isShiny: false,
      currentPokemon: null
    }
  },
  computed: {
    nbEvolutions() {
      let margin = ''

      switch (this.currentPokemon.evolutions.length) {
        case 1:
          margin = '0px 30px'
          break
        case 2:
          margin = '0px 25px'
          break
        case 3:
          margin = '0px 10px'
          break
      }

      return margin
    }
  },
  methods: {
    async search(pokemon) {
      this.show = true
      this.msg = ''

      try {
        const pokemonBasicInfo = await this.getPokemonBasicInfo(pokemon)
        const pokemonId = pokemonBasicInfo.id
        const pokemonDesc = await this.getPokemonDescription(pokemonId)
        const pokemonEvosId = this.parseEvosURL(pokemonDesc.evolution_chain.url)
        const pokemonEvolutions = await this.getPokemonEvolutions(pokemonEvosId)
        const pokemonChainEvolutions = await this.buildPokemonEvolutionsChain(pokemonEvolutions)

        this.currentPokemon = {
          id: pokemonId,
          name: this.firstLetterUppercase(pokemonBasicInfo.name),
          desc: this.getPokemonENDescription(pokemonDesc.flavor_text_entries),
          types: this.getPokemonTypes(pokemonBasicInfo.types),
          img: pokemonBasicInfo.sprites.front_default,
          shiny: pokemonBasicInfo.sprites.front_shiny,
          evolutions: pokemonChainEvolutions
        }
        this.show = false
      } catch (e) {
        this.show = false
        this.type = 'error'
        this.msg = 'Pokemon not found.'
      }
    },
    async getPokemonBasicInfo(pokemon) {
      const pokemonReq = await this.$axios.$get(`${process.env.POKEAPI_BASE_URL}/pokemon/${pokemon.toLowerCase()}`)

      return pokemonReq
    },
    async getPokemonSprite(pokemon) {
      const req = await this.$axios.$get(`${process.env.POKEAPI_BASE_URL}/pokemon/${pokemon.toLowerCase()}`)
      const sprite = req.sprites.front_default

      return sprite
    },
    async getPokemonDescription(id) {
      const pokemonDescReq = await this.$axios.$get(`${process.env.POKEAPI_BASE_URL}/pokemon-species/${id}`)

      return pokemonDescReq
    },
    getPokemonENDescription(languages) {
      for (const lang of languages) {
        if (lang.language.name === 'en') {
          return lang.flavor_text
        }
      }
    },
    async getPokemonEvolutions(id) {
      const pokemonEvolutions = await this.$axios.$get(`${process.env.POKEAPI_BASE_URL}/evolution-chain/${id}`)
      const hasEvolutions = pokemonEvolutions.chain.evolves_to.length
      const evolutions = []

      if (hasEvolutions === 1) {
        if (pokemonEvolutions.chain.evolves_to[0].evolves_to.length !== 0) {
          evolutions.push(pokemonEvolutions.chain.evolves_to[0].evolves_to[0].species.name)
        }
        evolutions.push(pokemonEvolutions.chain.evolves_to[0].species.name)
      }
      evolutions.push(pokemonEvolutions.chain.species.name)

      return evolutions.reverse()
    },
    async buildPokemonEvolutionsChain(evolutions) {
      const finalEvolutions = []

      for (const pokemon of evolutions) {
        const sprite = await this.getPokemonSprite(pokemon)

        const evolution = {
          name: pokemon,
          sprite
        }
        finalEvolutions.push(evolution)
      }
      return finalEvolutions
    },
    getPokemonTypes(pokemonTypes) {
      const types = []

      for (const i of pokemonTypes) {
        types.push(this.getImageOfType(i.type.name))
      }

      return types.reverse()
    },
    getImageOfType(type) {
      const types = {
        'bug': 'https://i.imgur.com/kpru1Y8.png',
        'dark': 'https://i.imgur.com/WKe2jzh.png',
        'dragon': 'https://i.imgur.com/bLtGPBd.png',
        'electric': 'https://i.imgur.com/nZbIwgv.png',
        'fairy': 'https://i.imgur.com/39kDaMO.png',
        'fighting': 'https://i.imgur.com/Pr97GQ1.png',
        'fire': 'https://i.imgur.com/ChmQPRq.png',
        'flying': 'https://i.imgur.com/ZO54bmh.png',
        'ghost': 'https://i.imgur.com/UroikHx.png',
        'grass': 'https://i.imgur.com/h0mdNN0.png',
        'ground': 'https://i.imgur.com/Z8AVJ4a.png',
        'ice': 'https://i.imgur.com/Adij2NC.png',
        'normal': 'https://i.imgur.com/T8MOm7P.png',
        'poison': 'https://i.imgur.com/Hh7FDun.png',
        'psychic': 'https://i.imgur.com/b7EgqXU.png',
        'rock': 'https://i.imgur.com/8fuHs1C.png',
        'steel': 'https://i.imgur.com/lmN1qDy.png',
        'water': 'https://i.imgur.com/OYx24YT.png'
      }

      return types[type]
    },
    parseId(id) {
      id = id.toString()
      return id.length === 1 ? '00' + id : id.length === 2 ? '0' + id : id
    },
    parseEvosURL(str) {
      return str.substring(42, str.length - 1)
    },
    firstLetterUppercase(str) {
      return str.replace(/^./, str[0].toUpperCase())
    }
  }
}
</script>

<style scoped lang="scss">
  .searchbar {
    margin: 0 10px -5px 10px;
  }
  .container {
    &__image {
      display: inline-block;
      vertical-align: top;
      width: 46%;
    }
    &__text {
      display: inline-block;
      width: 46%;
      @media (max-width: 620px) {
        width: 100%;
      }
    }
  .spacePokemon1 {
    margin: 0 30px;
  }
  .spacePokemon2 {
    margin: 0 25px;
  }
  .spacePokemon3 {
    margin: 0 20px;
  }

}
</style>
