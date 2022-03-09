/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int len;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        len = nums.size();
        vector<vector<int>> res = {{}};
        helpler(nums, 0, res);
        res.erase(remove_if(res.begin(), res.end(), [](vector<int> &elem)
                            { return elem.size() < 2; }),
                  res.end());
        return res;
    }
    void helpler(vector<int> &nums, int pos, vector<vector<int>> &res)
    {
        if (pos == len)
        {
            return;
        }
        int count = 1;
        while (pos + 1 != len && nums[pos] == nums[pos + 1])
        {
            ++pos;
            ++count;
        }
        int res_len = res.size();
        for (int i = 0; i != res_len; ++i)
        {
            if (i != 0 && res[i].back() > nums[pos])
            {
                continue;
            }
            for (int j = 1; j <= count; ++j)
            {
                res.push_back(res[i]);
                for (int k = 1; k <= j; ++k)
                {
                    res.back().push_back(nums[pos]);
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        helpler(nums, pos + 1, res);
    }
};
// @lc code=end
