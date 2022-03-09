/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;
// @lc code=start
class Twitter
{
public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        post_list[userId].push_back({++id, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        list<pair<int, int>> user_cur;
        if (!post_list[userId].empty())
        {
            user_cur.push_back({userId, post_list[userId].size() - 1});
        }
        for (auto &followeeId : follow_list[userId])
        {
            if (!post_list[followeeId].empty())
            {
                user_cur.push_back({followeeId, post_list[followeeId].size() - 1});
            }
        }
        int k = 11;
        while (--k && !user_cur.empty())
        {
            auto candidate = user_cur.begin();
            for (auto list_cur = next(user_cur.begin()); list_cur != user_cur.end(); ++list_cur)
            {
                if (post_list[list_cur->first][list_cur->second].first > post_list[candidate->first][candidate->second].first)
                {
                    candidate = list_cur;
                }
            }
            res.push_back(post_list[candidate->first][candidate->second].second);
            --candidate->second;
            if (candidate->second == -1)
            {
                user_cur.erase(candidate);
            }
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        follow_list[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        follow_list[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> follow_list;
    unordered_map<int, vector<pair<int, int>>> post_list;
    int id = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end