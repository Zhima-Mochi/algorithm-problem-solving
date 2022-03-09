/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1000)
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> rd(1001);
        for (auto &t : trips)
        {
            rd[t[1]] += t[0];
            rd[t[2]] -= t[0];
        }
        int p = 0;
        for (auto n : rd)
        {
            p += n;
            if (p > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
