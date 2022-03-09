/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        auto len = nums.size();
        if (len == 1)
        {
            return nums;
        }
        vector<int> val{INT_MAX, INT_MAX};
        vector<int> count(2);
        for (auto &n : nums)
        {
            if (val[0] == n)
            {
                ++count[0];
            }
            else if (val[1] == n)
            {
                ++count[1];
            }
            else
            {
                if (count[0] == 0)
                {
                    val[0] = n;
                    count[0] = 1;
                }
                else if (count[1] == 0)
                {
                    val[1] = n;
                    count[1] = 1;
                }
                else
                {
                    --count[0];
                    --count[1];
                }
            }
        }
        vector<int> res;
        auto count1 = 0, count2 = 0;
        for (auto &n : nums)
        {
            if (n == val[0])
            {
                ++count1;
            }
            if (n == val[1])
            {
                ++count2;
            }
            if (count1 > len / 3 && count2 > len / 3)
            {
                break;
            }
        }
        if (count1 > len / 3)
        {
            res.push_back(val[0]);
        }
        if (count2 > len / 3)
        {
            res.push_back(val[1]);
        }
        return res;
    }
};
// @lc code=end
