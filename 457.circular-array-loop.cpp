/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */
#include <vector>
using namespace std;
// @lc code=start

//T: O(n) S: O(1)
class Solution
{

public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i != len; ++i)
        {
            if (nums[i] != 0)
            {
                auto current_index = i;
                auto shift = nums[i];
                while (shift < len * 1001 && shift > -len * 1001)
                {
                    nums[current_index] = shift > 0 ? len * 1001 + shift : -len * 1001 + shift;
                    current_index = ((current_index + shift) % len + len) % len;
                    shift = nums[current_index];
                    if (shift == 0)
                    {
                        break;
                    }
                }
                //check cycle is validate or not and set zero
                bool is_same_sign = true;
                int count = 0;
                while (shift != 0)
                {
                    ++count;
                    nums[current_index] = 0;
                    current_index = ((current_index + shift) % len + len) % len;
                    if ((shift % len) * (nums[current_index] % len) < 0)
                    {
                        is_same_sign = false;
                    }
                    shift = nums[current_index];
                }
                if (count > 1 && is_same_sign)
                {
                    return true;
                }
                //set all the postion passed through zero
                current_index = i;
                shift = nums[i];
                while (shift != 0)
                {
                    nums[current_index] = 0;
                    current_index = ((current_index + shift) % len + len) % len;
                    shift = nums[current_index];
                }
            }
        }
        return false;
    }
};
// @lc code=end
