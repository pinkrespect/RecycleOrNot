""" test.py

"""
import tweepy
from tweepy.streaming import StreamListener
from konlpy.tag import Kkma

from sqlalchemy import insert
from auth import C_KEY, C_SECRET, A_TOKEN, A_SECRET

AUTH = tweepy.OAuthHandler(C_KEY, C_SECRET)
AUTH.set_access_token(A_TOKEN, A_SECRET)

API = tweepy.API(AUTH, wait_on_rate_limit=True,
                 wait_on_rate_limit_notify=True)

ME = API.me()
MY_NAME = '@' + (ME.screen_name).lower()

print(" * name: " + MY_NAME + " *")


class Timeline(StreamListener):
    def on_status(self, status):
        timelines = API.user_timeline(count=1)
        for timeline in timelines:
            url = "https://twitter.com/" + ME.screen_name.lower() + "/status/"
            url += str(timeline.id)
            print(" [ " + timeline.text + " ] " + url)
            kkma = Kkma()
            poslist = kkma.pos(timeline.text)
            for word in poslist:
                if word[1] == 'NNG':
                    nnglist = list()
                    nnglist += word[0]
                    print(nnglist)

# Reminder: Hashtag String
# Read Later: Favorite


listener = Timeline()
stream = tweepy.Stream(auth=AUTH, listener=listener)
stream.userstream(_with="user")




