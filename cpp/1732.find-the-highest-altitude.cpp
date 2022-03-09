/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = max(0, gain[0]);
        for (int i = 1, width = gain.size(); i != width; ++i)
        {
            gain[i] += gain[i - 1];
            res = max(res, gain[i]);
        }
        return res;
    }
};
// @lc code=end
