/*
 * @lc app=leetcode id=2560 lang=cpp
 *
 * [2560] House Robber IV
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(nlog(m), s:O(1))
class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int noRob = 0, robbed = 0;
            int mid = left + (right - left) / 2;
            for (auto n : nums)
            {
                if (n > mid)
                {
                    noRob = max(noRob, robbed);
                    robbed = 0;
                }
                else
                {
                    int temp = robbed;
                    robbed = noRob + 1;
                    noRob = max(noRob, temp);
                }
                if (noRob >= k || robbed >= k)
                {
                    break;
                }
            }
            if (noRob < k && robbed < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
