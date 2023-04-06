/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */
#include <string>
using namespace std;
// @lc code=start
// t: O(n) s: O(1)
class Solution
{
public:
    int partitionString(string s)
    {
        int res = 1;
        int val = 0;
        for (auto c : s)
        {
            if (val & 1 << (c - 'a'))
            {
                res += 1;
                val = 1 << (c - 'a');
            }
            else
            {
                val |= 1 << (c - 'a');
            }
        }
        return res;
    }
};
// @lc code=end