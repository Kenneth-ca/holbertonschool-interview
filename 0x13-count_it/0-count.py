#!/usr/bin/python3
"""Queries the Reddit API"""
import requests


def count_words(subreddit, word_list):
    """Returns the count of given words"""
    try:
        url = 'https://www.reddit.com/r/' + subreddit + '/hot.json'
        header = {'User-agent': 'Kenneth98765421'}
        limit = {'limit': '10'}
        resp = requests.get(url, headers=header,
                            params=limit, allow_redirects=False).json()
        key = resp.get('data').get('children')
        for value in key:
            print(value.get('data').get('title'))
    except:
        print(None)
