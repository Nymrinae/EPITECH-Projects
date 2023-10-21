# Recommender Kick Off

We will have in our hands on a dataset containing around 7 million bought items. The company expects us to build a recommendation system to offer a gift to each client based on their preferences. This document will explain how we are going to "pre-process" our dataset.

  ## Problem specification and understanding
 - Build a recommendation system based on items
 - Cluster clients to analyze consumer demograpchics
 - Propose a solution to recommend a item based on customer data

  ## Data cleaning
Before analysing the dataset, we need to clean the data by checking first if there is some missing data and then, maybe fetching only useful informations from the dataset instead of handling the whole dataset for better performance

  ## Data understanding
According to the subject, each item of the dataset is divided into three categories: Famille, Univers and Maille. We will suppose that they are more columns such as an item ID, item's name, the client ID who bought the item and probably more. Our first goal is to have a global view of the dataset.

  ## Data exploration
As mentioned on the previous part, we are going to start with a global analysis of the dataset such as, based on items:
  - most popular items of each category
  - most popular items depending on the month of the year
  - mean price for each item of each category
  - ...

and based on clients:
  - mean price spend by ticket
  - mean number of items per ticket
  - ...

This data will be translated into graphics.

 ## Data analysis

To recommend products, we are going to use an IBCF (Item Based Collaborative Filtering) first to recommend some similar items based on what they already bought. We are going to check first if they are similar (same univers, famille, maille?). Since we will probably dont have data about if the user liked the product or not (not like a movie for example) we will take the number of times the item has been bought as a metric value.
This system could be a solution but since we don't have detailed rating or such maybe moving to a UBCF (User based Collaborative Filtering) will help us better in the second place.

 ## Final goal

Our final goal is to provide a complete analysis based on a given client:
 - a statistical description based on the data we have gathered previously
 - an analysis of the client (type of client, behaviour...)
 - recommending an gift based on this data