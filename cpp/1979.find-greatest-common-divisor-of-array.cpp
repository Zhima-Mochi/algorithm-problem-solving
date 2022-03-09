/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        while (min_val != 0)
        {
            int temp = max_val % min_val;
            max_val = min_val;
            min_val = temp;
        }
        return max_val;
    }
};
// @lc code=end
