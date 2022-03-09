/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        auto len = nums.size();
        if (len == 0)
        {
            return res;
        }
        int cur_num = nums[0];
        int prev_num = cur_num;
        for (int i = 1; i != len; ++i)
        {
            if (nums[i] != ++prev_num)
            {
                if (cur_num == prev_num - 1)
                {
                    res.push_back(to_string(cur_num));
                }
                else
                {
                    res.push_back(to_string(cur_num));
                    res.back().append("->");
                    res.back().append(to_string(prev_num - 1));
                }
                cur_num = nums[i];
                prev_num = cur_num;
            }
        }
        if (cur_num != prev_num)
        {
            res.push_back(to_string(cur_num));
            res.back().append("->");
            res.back().append(to_string(prev_num));
        }
        else
        {
            res.push_back(to_string(cur_num));
        }
        return res;
    }
};
// @lc code=end
