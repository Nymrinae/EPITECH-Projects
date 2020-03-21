export const about = {
  "server": {
    "current_time": Math.floor(Date.now() / 1000),
    "services": [{
      "name": "discord",
      "reactions": [{
        "name": "post_discord_message",
        "description": "Post a discord message when triggered"
      }]
    },
    {
      "name": "gmail",
      "reactions": [{
        "name": "send_mail",
        "description": "Send a mail depending on the action chosen"
      }]
    },
    {
      "name": "intra",
        "actions": [{
          "name": "project_subscribe",
          "description": "The user signs up for a project"
        },
        {
          "name": "activity_subscribe",
          "description": "The user signs up for an activity"
        },
        {
          "name": "module_subscribe",
          "description": "The user signs up for a module"
        }],
        "reactions": [{
          "name": "send_mail",
          "description": "Send confirmation mail"
        },
        {
          "name": "post_discord_message",
          "description": "Post a confirmation in Discord"
        }]
    },
    {
      "name": "reddit",
      "actions": [{
        "name": "search_on_reddit",
        "description": "search the latest 5 posts on a subreddit"
      }],
      "reactions": [{
        "name": "get_post",
        "description": "get details when a post in posted on a subreddit"
      }]
    },
    {
      "name": "twitter",
      "actions": [{
        "name": "tweet",
        "description": "Tweet"
      }],
      "reactions": [{
        "name": "send_mail",
        "description": "Send confirmation mail"
      },
      {
        "name": "tweet_listener",
        "description": "get tweet info when soemething happens (like, rt...)"
      },
      {
        "name": "post_discord_message",
        "description": "Post a confirmation in Discord"
      }]
    }]
  }
}