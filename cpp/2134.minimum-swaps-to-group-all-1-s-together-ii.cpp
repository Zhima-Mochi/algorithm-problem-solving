/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int one_cnt = 0;
        for (auto n : nums)
        {
            if (n)
            {
                one_cnt++;
            }
        }
        int cur_cnt = 0;
        int left = 0, right = 0;
        int w = nums.size();
        for (int i = 0; i != w; ++i)
        {
            nums.push_back(nums[i]);
        }
        for (int i = 0; i != one_cnt; ++i)
        {
            if (nums[right] == 1)
            {
                cur_cnt++;
            }
            right++;
        }
        int res = one_cnt - cur_cnt;

        for (int i = 0; i != w; ++i)
        {
            if (nums[right] == 1)
            {
                cur_cnt++;
            }
            right++;
            if (nums[left] == 1)
            {
                cur_cnt--;
            }
            left++;
            res = min(res, one_cnt - cur_cnt);
        }
        return res;
    }
};
// @lc code=end
