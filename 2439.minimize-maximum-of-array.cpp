/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t: O(nlogn) s: O(1)
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int right = *max_element(nums.begin(), nums.end());
        int left = *min_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long long val = 0;
            for (auto n : nums)
            {
                if (n < mid)
                {
                    val += mid - n;
                }
                else
                {
                    val -= n - mid;
                }
                if (val < 0)
                {
                    break;
                }
            }
            if (val < 0)
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
