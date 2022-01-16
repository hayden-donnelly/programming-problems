from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from csv import writer
import time

start_page = 1
pages_to_scrape = 1
sleep_time = 2

options = Options()
options.headless = True
driver = webdriver.Chrome(options=options)

def load_page(page_num):
    global driver
    driver.get('https://coinmarketcap.com/?page=' + str(page_num))

driver.execute_script("window.scrollTo(0, 750)")

with open('cryptocurrencies.csv', 'w', encoding='utf8', newline='') as f:
    tw = writer(f)
    tw.writerow(['name', 'symbol', 'price', 'market cap', 'circulating supply'])
    
    for page_num in range(start_page-1, pages_to_scrape):
        load_page(page_num+1)
        driver.execute_script("window.scrollTo(0, 750)")

        for i in range(10):
            soup = BeautifulSoup(driver.page_source, 'html.parser')
            table_entries = soup.find_all('tbody')[0].find_all('tr')[i*10:i*10+10]

            for table_entry in table_entries:
                name = table_entry.find('p', class_='sc-1eb5slv-0 iworPT').text
                symbol = table_entry.find('p', class_='sc-1eb5slv-0 gGIpIK coin-item-symbol').text
                price = table_entry.find('div', class_='sc-131di3y-0 cLgOOr').find('span').text
                market_cap = table_entry.find('p', class_='sc-1eb5slv-0 hykWbK').find('span', class_='sc-1ow4cwt-1 ieFnWP').text
                circulating_supply = table_entry.find('p', class_='sc-1eb5slv-0 kZlTnE').text
                tw.writerow([name, symbol, price, market_cap, circulating_supply])

            driver.execute_script("window.scrollTo(0, window.scrollY + 1100)")
            time.sleep(sleep_time)