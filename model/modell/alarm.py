import datetime
import time
while True:
    now = datetime.datetime.now()
    if now.hour == 17 and now.minute == 14:
        print("去吃饭")
    time.sleep(15)