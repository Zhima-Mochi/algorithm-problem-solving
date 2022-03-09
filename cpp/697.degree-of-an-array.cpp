/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        vector<unsigned short> first_pos(50000);
        vector<unsigned short> count(50000);
        int degree = 0;
        int len = nums.size();
        int res = 0;
        for (int i = 0; i != len; ++i)
        {
            if (first_pos[nums[i]] == 0)
            {
                first_pos[nums[i]] = i + 1;
            }
            if (++count[nums[i]] > degree)
            {
                degree = count[nums[i]];
                res = i + 2 - first_pos[nums[i]];
            }
            else if (count[nums[i]] == degree)
            {
                res = min(i + 2 - first_pos[nums[i]], res);
            }
        }
        return res;
    }
};
// @lc code=end
