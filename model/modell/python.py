import requests
import os
import time

header = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7", 
    "Accept-Encoding": "gzip, deflate", 
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6", 
    "Host": "httpbin.org", 
    "Upgrade-Insecure-Requests": "1", 
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36 Edg/110.0.1587.50", 
    "X-Amzn-Trace-Id": "Root=1-63f1c609-1cdec9653d3a63a23b85714d"
}
x = requests.get('https://api.jitsu.top/img', allow_redirects=False)

url_set = ['https://api.jitsu.top/img']

def bar(i, num):
    print('\r[%3.2f%%]: |%-50s|' % (100 * i / num, '▋' * (50 * i // num)),
          end='',
          flush=True)

def get_url(num):
    url = ""
    for url in url_set:
        if requests.get(url, allow_redirects = False).status_code != 503:
            print("The default link is not available, and has been switched to an alternate link")
        else:
            if url == url_set[-1]:
                print("All the links is not available")
                return -1
            continue

    for i in range(1, num + 1):
        response = requests.get(url)
        image_name = response.url.split('/')[-1]

        image = response.content
        image = response.content
        if not os.path.exists('./pics/'):
            os.mkdir('./pics/')
        try:
            with open('./pics/%s' % image_name.split('&')[0], 'wb') as file:
                file.write(image)
        except PermissionError:
            i -= 1
            continue
        bar(i, num)
if __name__ == '__main__':
    n = int(input('Gets the number of images:'))
    get_url(n)
