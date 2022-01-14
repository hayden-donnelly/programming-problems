from bs4 import BeautifulSoup
from word2number import w2n
from csv import writer
from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
driver.get('http://books.toscrape.com/catalogue/category/books_1/index.html')

with open('books.csv', 'w', encoding='utf8', newline='') as f:

    tw = writer(f)
    header = ['Title', 'Price (Euros)', 'Star Rating']
    tw.writerow(header)

    # Website has 50 pages
    for i in range(49):
        next_page = driver.find_elements(By.LINK_TEXT, 'next')
        next_page[0].click()
        
        soup = BeautifulSoup(driver.page_source, 'html.parser')
        lists = soup.find_all('article', class_='product_pod')
        
        for list in lists:
            # Selects title attribute
            title = list.select_one('a[title]')['title']
            price = list.find('p', class_='price_color').text[1:]
            # Converts word ratings to number ratings
            star_rating = w2n.word_to_num(list.select_one('p[class*="star-rating"]')['class'][1])
            info = [title, price, star_rating]
            tw.writerow(info)
