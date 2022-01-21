import os
import requests
import time
import json

def input_path():
    path = input ("Please input path to directory: ")
    return path

def input_webhook_url():
    webhook_url = input("Please input Discord Webhook url: ")
    return webhook_url

# Sends a notification of file additions to Discord Webhook.
def notify(files_added, num_files_added):
    message = '**{} file(s) have been added:**\n'.format(num_files_added)
    for file in files_added:
        message += '{}\n'.format(file)
    
    data = {"embeds": [{"description": message, "color": 0}]}
    print(requests.post(webhook_url, json=data))

# Checks directy to see if files have been added.
def check_dir():
    files_added = []
    for file in os.listdir(path):
        file_name = os.path.join(path, file)
        if file_name in files:
            continue
        files.append(file_name)
        files_added.append(file)
    
    num_files_added = len(files_added)
    if num_files_added >= 1:
        notify(files_added, num_files_added)

try:
    with open('config.json', 'r') as f:
        data = f.read()
except:
    with open('config.json', 'w') as f:
        json.dump({"directory": "", "webhook_url": ""}, f)
        data = f.read()

config = json.loads(data)
path = config['directory']
webhook_url = config['webhook_url']
files = []

if path == '':
    path = input_path()
else:
    update_path = ''
    while update_path != 'y' and update_path != 'n':
        update_path = input("Would you like to update the path to directory? (y/n) ")
    if update_path == 'y':
        input_path()

if webhook_url == '':
    webhook_url = input_webhook_url()
else:
    update_webhook_url = ''
    while update_webhook_url != 'y' and update_webhook_url != 'n':
        update_webhook_url = input("Would you like to update the webhook url? (y/n) ")
    if update_webhook_url == 'y':
        input_webhook_url()

with open('config.json', 'w') as f:
    new_config = {"directory": path, "webhook_url": webhook_url}
    json.dump(new_config, f)

# Checks directory every 10 seconds to see if files have been added.
while True:
    check_dir()
    time.sleep(10)
