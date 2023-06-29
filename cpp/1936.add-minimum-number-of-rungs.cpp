/*
 * @lc app=leetcode id=1936 lang=cpp
 *
 * [1936] Add Minimum Number of Rungs
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        int res = 0;
        int w = rungs.size();
        for (int i = 0; i != w; ++i)
        {
            if (i == 0)
            {
                res += (rungs[i] - 1) / dist;
            }
            else
            {
                res += (rungs[i] - rungs[i - 1] - 1) / dist;
            }
        }
        return res;
    }
};
// @lc code=end
