/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        deque<bool> memo(3);
        memo[0] = true;
        if (nums[1] == nums[0])
        {
            memo[2] = true;
        }
        int w = nums.size();
        for (int i = 2; i != w; ++i)
        {
            if (nums[i] == nums[i - 1] && memo[1])
            {
                memo.push_back(true);
            }
            else if (memo[0] && nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
            {
                memo.push_back(true);
            }
            else if (memo[0] && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2 && memo[0])
            {
                memo.push_back(true);
            }
            else
            {
                memo.push_back(false);
            }
            memo.pop_front();
            if (memo[0] == false && memo[1] == false && memo[2] == false)
            {
                return false;
            }
        }
        return memo[2];
    }
};
// @lc code=end
