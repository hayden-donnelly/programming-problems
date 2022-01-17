# CoinMarketCap

This script uses Selenium and BS4 to scrape data on various cryptocurrencies from [CoinMarketCap](https://coinmarketcap.com/).

## Output
A CSV file containing all of the scraped data, e.g.

| name       | symbol | price | market cap | circulating supply |
|-------------|---------------|-------------|-----------|-------|
| Bitcoin | BTC         | $43,091.96           | $815,752,586,291          | 18,930,506 BTC          |
| Ethereum | ETH        | $3,324.96           | $396,256,265,596          | 119,176,306 ETH          |
| BNB | BNB         | $494.32          | $82,453,469,110           | 166,801,148 BNB |
| Tether | USDT         | $1.00           | $78,426,593,036          | 78,399,569,301 USDT          |
| ... | ...         | ...           | ... | ... |
| Velas | 26.08         | Velas           | $0.3623          | $814,666,385          | 2,248,438,278 VLX |

```
name,symbol,price,market cap,circulating supply
Bitcoin,BTC,"$43,091.96","$815,752,586,291","18,930,506 BTC"
Ethereum,ETH,"$3,324.96","$396,256,265,596","119,176,306 ETH"
BNB,BNB,$494.32,"$82,453,469,110","166,801,148 BNB"
Tether,USDT,$1.00,"$78,426,593,036","78,399,569,301 USDT"
...
Velas,Velas,$0.3623,"$814,666,385","2,248,438,278 VLX"
```
