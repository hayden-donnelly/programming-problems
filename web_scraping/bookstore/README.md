# Bookstore

This script uses Selenium and BS4 to scrape the title, price, and rating from all books in a fake bookstore. It requires chromedriver.

## Output
A CSV file containing all of the scraped data, e.g.

| Title       | Price (Euros) | Star Rating |
|-------------|---------------|-------------|
| In Her Wake | 12.84         | 1           |
| How Music Works | 37.32        | 2           |
| Black Dust | 34.53         | 5           |
| Birdsong: A Story in Pictures | 54.64         | 3           |
| ... | ...         | ...           |
| "1,000 Places to See Before You Die" | 26.08         | 5           |

```
Title,Price (Euros),Star Rating
In Her Wake,12.84,1
How Music Works,37.32,2
Black Dust,34.53,5
Birdsong: A Story in Pictures,54.64,3
...
"1,000 Places to See Before You Die",26.08,5
```
