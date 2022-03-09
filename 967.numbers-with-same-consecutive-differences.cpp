/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(2^n), s:O(2^n)
class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        while (--n)
        {
            vector<int> next_res;
            for (auto val : res)
            {
                if (val % 10 + k < 10)
                {
                    next_res.push_back(val * 10 + val % 10 + k);
                }
                if (k > 0 && val % 10 - k >= 0)
                {
                    next_res.push_back(val * 10 + val % 10 - k);
                }
            }
            res = move(next_res);
        }
        return res;
    }
};
// @lc code=end
