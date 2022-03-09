/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = nums[0];
        int cur_val = 0;
        auto len = nums.size();
        for (size_t i = 0; i != len; i++)
        {
            if (cur_val + nums[i] > max)
            {
                if(nums[i]<0){
                    cur_val=0;
                    max=nums[i];
                }else{
                    max = cur_val += nums[i];
                }
                
            }
            else if (cur_val + nums[i] <= 0)
            {
                if (nums[i] < 0)
                {
                    cur_val = 0;
                }
                else
                {
                    cur_val = nums[i];
                    if (cur_val > max)
                    {
                        max = cur_val;
                    }
                }
            }
            else
            {
                cur_val += nums[i];
            }
        }
        return max;
    }
};
// @lc code=end
