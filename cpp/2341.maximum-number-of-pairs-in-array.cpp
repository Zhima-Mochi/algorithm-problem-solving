/*
 * @lc app=leetcode id=2341 lang=cpp
 *
 * [2341] Maximum Number of Pairs in Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> records(101, 0);
        vector<int> res = {0, 0};
        int w = nums.size();
        for (auto n : nums)
        {
            records[n] ^= 1;
            if (records[n] == 0)
            {
                res[0] += 1;
            }
        }
        res[1] = w - res[0] * 2;
        return res;
    }
};
// @lc code=end
