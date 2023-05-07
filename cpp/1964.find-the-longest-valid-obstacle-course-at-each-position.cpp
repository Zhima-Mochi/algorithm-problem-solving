/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start
// t: O(nlogn), s: O(n)
class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> increasing;
        increasing.reserve(obstacles.size());
        vector<int> res;
        for (auto o : obstacles)
        {
            auto it = upper_bound(increasing.begin(), increasing.end(), o);
            if (it == increasing.end())
            {
                increasing.push_back(o);
                res.push_back(increasing.size());
            }
            else
            {
                *it = o;
                res.push_back(it - increasing.begin() + 1);
            }
        }
        return res;
    }
};
// @lc code=end
