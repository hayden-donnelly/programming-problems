# CoinMarketCap

This script uses Selenium and BS4 to scrape data on various cryptocurrencies from [CoinMarketCap](https://coinmarketcap.com/).

## Output
A CSV file containing all of the scraped data, e.g.

| name       | symbol | price | market cap | circulating supply |
|-------------|---------------|-------------|-----------|-------|
| Bitcoin | BTC         | $43,091.96           | $815,752,586,291          | 18,930,506 BTC          |
| How Music Works | 37.32        | 2           |           |           |
| Black Dust | 34.53         | 5           |
| Birdsong: A Story in Pictures | 54.64         | 3           |           |           |
| ... | ...         | ...           |
| "1,000 Places to See Before You Die" | 26.08         | 5           |           |           |

```
Title,Price (Euros),Star Rating
In Her Wake,12.84,1
How Music Works,37.32,2
Black Dust,34.53,5
Birdsong: A Story in Pictures,54.64,3
...
"1,000 Places to See Before You Die",26.08,5
```
