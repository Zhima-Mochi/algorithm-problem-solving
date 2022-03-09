/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        char val = 0;
        vector<bool> res;
        for (auto n : nums)
        {
            val <<= 1;
            val += n;
            val %= 5;
            res.push_back(val == 0);
        }
        return res;
    }
};
// @lc code=end
