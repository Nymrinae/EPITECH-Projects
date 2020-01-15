module.exports = {
    parseURL: url => {
    const urlInfos = url.split('#').pop().split('&');
    const userInfos = {
      accessToken: urlInfos[0].split('=')[1],
      accountId: urlInfos[5].split('=')[1],
      accountUsername: urlInfos[4].split('=')[1]
    }

    return userInfos
  },
  convertTimestampToDate: timestamp => {
    let date = new Date(timestamp * 1000).toString()

    date = date.split(' ')

    return `${date[1]} ${date[2]}, ${date[3]}`
  }
}
