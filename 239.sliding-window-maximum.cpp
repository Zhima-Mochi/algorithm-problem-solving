/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <set>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> num_pq;
        for (int i = 0; i != k; ++i)
        {
            num_pq.push({nums[i], i});
        }
        int w = nums.size();
        vector<int> res;
        res.push_back(num_pq.top().first);
        for (int i = k; i != w; ++i)
        {
            num_pq.push({nums[i], i});
            while (num_pq.top().second <= i - k)
            {
                num_pq.pop();
            }
            res.push_back(num_pq.top().first);
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         multiset<int> num_set(nums.begin(), nums.begin() + k);
//         int w = nums.size();
//         vector<int> res;
//         res.push_back(*prev(num_set.end()));
//         for (int i = k; i != w; ++i)
//         {
//             num_set.erase(num_set.find(nums[i - k]));
//             num_set.insert(nums[i]);
//             res.push_back(*prev(num_set.end()));
//         }
//         return res;
//     }
// };