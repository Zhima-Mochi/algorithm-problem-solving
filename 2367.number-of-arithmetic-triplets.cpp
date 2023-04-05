/*
 * @lc app=leetcode id=2367 lang=cpp
 *
 * [2367] Number of Arithmetic Triplets
 */
#include <vector>
using namespace std;
// @lc code=start
// t: O(n) s: O(1)
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int res = 0;
        int w = nums.size();
        if (w < 3)
        {
            return 0;
        }
        int p1 = 1, p2 = 2;
        for (int i = 0; i != w; ++i)
        {
            while (p1 < w && nums[p1] - nums[i] < diff)
            {
                p1 += 1;
            }
            if (p1 >= w)
            {
                break;
            }
            if (p2 <= p1)
            {
                p2 = p1 + 1;
            }
            while (p2 < w && nums[p2] - nums[p1] < diff)
            {
                p2 += 1;
            }
            if (p2 >= w)
            {
                break;
            }
            if (nums[p1] - nums[i] == diff && nums[p2] - nums[p1] == diff)
            {
                res += 1;
            }
        }
        return res;
    }
};
// @lc code=end
