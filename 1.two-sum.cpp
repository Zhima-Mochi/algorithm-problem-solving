/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        unordered_map<int, short> umap;
        for (int i = 0; i != len; ++i)
        {
            if (umap.count(nums[i]))
            {
                return vector<int>{umap[nums[i]], i};
            }
            else
            {
                umap[target - nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
// @lc code=end
