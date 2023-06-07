/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n) s:O(n)
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int w = nums.size();
        while (right < w)
        {
            if (right + 1 < w && nums[right] == nums[right + 1])
            {
                nums[left] = 2 * nums[right];
                right += 2;
            }
            else
            {
                nums[left] = nums[right];
                right++;
            }
            if (nums[left] != 0)
            {
                left++;
            }
        }
        while (left < w)
        {
            nums[left] = 0;
            left++;
        }
        return nums;
    }
};
// @lc code=end
