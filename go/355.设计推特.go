/*
 * @lc app=leetcode.cn id=355 lang=golang
 *
 * [355] 设计推特
 */
package main

import "container/list"

// @lc code=start

type User struct {
	followees map[int]struct{}
	tweets    *list.List
}

func NewUser() *User {
	return &User{
		followees: map[int]struct{}{},
		tweets:    list.New(),
	}
}

type Twitter struct {
	users     map[int]*User
	tweetTime map[int]int
	count     int
	timestamp int
}

func Constructor() Twitter {
	return Twitter{
		users:     make(map[int]*User),
		tweetTime: make(map[int]int),
		count:     10,
		timestamp: 0,
	}
}

func (this *Twitter) PostTweet(userId int, tweetId int) {
	if _, ok := this.users[userId]; !ok {
		this.users[userId] = NewUser()
	}
	user := this.users[userId]
	user.tweets.PushFront(tweetId)
	if user.tweets.Len() > this.count {
		user.tweets.Remove(user.tweets.Back())
	}
	this.tweetTime[tweetId] = this.timestamp
	this.timestamp++
}

func (this *Twitter) GetNewsFeed(userId int) []int {
	if _, ok := this.users[userId]; !ok {
		this.users[userId] = NewUser()
	}
	targets := []*list.Element{}
	targets = append(targets, this.users[userId].tweets.Front())
	for followeeId := range this.users[userId].followees {
		targets = append(targets, this.users[followeeId].tweets.Front())
	}
	ans := []int{}
	for len(ans) < this.count {
		newestTweetsIdx := -1
		for i, tweets := range targets {
			if tweets == nil {
				continue
			}
			if newestTweetsIdx == -1 {
				newestTweetsIdx = i
			} else if this.tweetTime[targets[newestTweetsIdx].Value.(int)] < this.tweetTime[tweets.Value.(int)] {
				newestTweetsIdx = i
			}
		}
		if newestTweetsIdx == -1 {
			break
		}
		ans = append(ans, targets[newestTweetsIdx].Value.(int))
		targets[newestTweetsIdx] = targets[newestTweetsIdx].Next()
	}
	return ans
}

func (this *Twitter) Follow(followerId int, followeeId int) {
	if _, ok := this.users[followerId]; !ok {
		this.users[followerId] = NewUser()
	}
	if _, ok := this.users[followeeId]; !ok {
		this.users[followeeId] = NewUser()
	}
	this.users[followerId].followees[followeeId] = struct{}{}
}

func (this *Twitter) Unfollow(followerId int, followeeId int) {
	delete(this.users[followerId].followees, followeeId)
}

/**
 * Your Twitter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PostTweet(userId,tweetId);
 * param_2 := obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */
// @lc code=end
