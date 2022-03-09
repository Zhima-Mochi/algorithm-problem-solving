/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i != len; ++i)
        {
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        }
        vector<int> res;
        for (int i = 0; i != len; ++i)
        {
            if (nums[i] >= 0)
            {
                res.push_back(i + 1);
            }
        }
        return res;
        // int len = nums.size();
        // for (int i = 0; i != len; ++i)
        // {
        //     if (nums[i] != i + 1)
        //     {
        //         while (nums[nums[i] - 1] != nums[i])
        //         {
        //             swap(nums[nums[i] - 1], nums[i]);
        //         }
        //     }
        // }
        // vector<int> res;
        // for (int i = 0; i != len; ++i)
        // {
        //     if (nums[i] != i + 1)
        //     {
        //         res.push_back(i + 1);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
