/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        pings.push_back(t);
        return pings.end() - lower_bound(pings.begin(), pings.end(), t - 3000);
    }

private:
    vector<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

// class RecentCounter
// {
// public:
//     RecentCounter()
//     {
//     }

//     int ping(int t)
//     {
//         pings.push_back(t);
//         while (pings.front() < t - 3000)
//         {
//             pings.pop_front();
//         }
//         return pings.size();
//     }

// private:
//     deque<int> pings;
// };