/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int width = nums.size();
        int end_pos = width % 2 ? width - 2 : width - 1;
        int cur = 0;
        while (cur != end_pos)
        {
            if (nums[end_pos] % 2 == 0)
            {
                swap(nums[cur], nums[end_pos]);
                cur += 2;
                if (cur >= width)
                {
                    //cur = 1;
                    break;
                }
            }
            else
            {
                end_pos -= 2;
                if (end_pos < 0)
                {
                    //end_pos = width % 2 ? width - 1 : width - 2;
                    break;
                }
            }
        }
        return nums;
    }
};
// @lc code=end
