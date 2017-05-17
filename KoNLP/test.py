""" test.py

"""
import tweepy
from tweepy.streaming import StreamListener

import sqlalchemy
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
        print('hello')
        timelines = API.home_timeline()
        for timeline in timelines:
            print(timeline.text)
        
        mentions = API.mentions_timeline(count=1)
        for mention in mentions:
            print(mention.text)


listener = Timeline()
stream = tweepy.Stream(auth=AUTH, listener=listener)
stream.userstream()


# TODO: It doesn't work. It can't holding itself.
