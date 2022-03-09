/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto n = nums.begin() + 2, iterEnd = nums.end(); n != iterEnd; ++n)
        {
            if (*n + *prev(n) > *prev(n, 2))
            {
                return *n + *prev(n) + *prev(n, 2);
            }
        }
        return 0;
    }
};
// @lc code=end
