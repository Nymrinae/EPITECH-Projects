
type Nullable<T> = T | null | undefined

type Movie = {
  actors: string
  avg_vote: number
  budget: Nullable<number>
  country: string
  date_published: string
  description: string
  director: string
  duration: number
  genre: string
  imdb_title_id: string
  language: string
  metascore: number
  original_title: string
  production_company: string
  reviews_from_critics: number
  reviews_from_users: number
  title: string
  usa_gross_income: number
  vote: number
  worlwide_gross_income: number
  writer: string
  year: string
}