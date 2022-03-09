/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int res = -1;
        int max_val = values[0];
        int w = values.size();
        for (int i = 1; i != w; ++i)
        {
            res = max(res, max_val + values[i] - i);
            max_val = max(max_val, values[i] + i);
        }
        return res;
    }
};
// @lc code=end
