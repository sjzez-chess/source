import requests

response = requests.get('https://www.python.org/get')
response.status_code
print(response)