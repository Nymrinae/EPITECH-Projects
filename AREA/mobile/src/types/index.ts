interface User {
  avatar?: any,
  username?: string,
  email: string,
  password: string
}

interface FormState extends User {
  errorMsg: string
}

export {
  FormState,
  User
}