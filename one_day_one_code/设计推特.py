from typing import List
import heapq

import collections


class Twitter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        #用户字典格式 k:userId -> v:userContent(包含F以及T)
        self.user = {}
        #推文绝对id
        self.Tid = 0

    def _new_user(self, userId):
        #F followee关注的人 初始关注自己
        F = {userId}
        #推文列表，长度为10
        T = collections.deque(maxlen=10)
        self.user[userId] = {'F':F, 'T':T}

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        if userId not in self.user:
            self._new_user(userId)
        self.user[userId]['T'].append((self.Tid, tweetId))
        self.Tid += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        if userId not in self.user:
            return []
        Tlist = []
        for uid in self.user[userId]['F']:
            Tlist.extend(list(self.user[uid]['T']))
        T10 = heapq.nlargest(10, Tlist)
        # return T10
        return [T[1] for T in T10]

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId not in self.user:
            self._new_user(followerId)
        if followeeId not in self.user:
            self._new_user(followeeId)
        self.user[followerId]['F'].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followeeId in self.user and followerId in self.user and followerId != followeeId:
            self.user[followerId]['F'].discard(followeeId)



        # Your Twitter object will be instantiated and called as such:
        # obj = Twitter()
        # obj.postTweet(userId,tweetId)
        # param_2 = obj.getNewsFeed(userId)
        # obj.follow(followerId,followeeId)
        # obj.unfollow(followerId,followeeId)
def main():
    obj = Twitter()
    obj.postTweet('a', 4)
    obj.follow('a', 'b')
    obj.postTweet('a', 5)
    obj.postTweet('a', 6)
    obj.postTweet('b', 1)
    aram_2 = obj.getNewsFeed('a')
    print(aram_2)

if __name__ == '__main__':
    main()