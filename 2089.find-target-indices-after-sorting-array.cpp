/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int count = 0;
        int smaller = 0;
        for (auto n : nums)
        {
            if (n < target)
            {
                ++smaller;
            }
            else if (n == target)
            {
                ++count;
            }
        }
        vector<int> res(count);
        iota(res.begin(), res.end(), smaller);
        return res;
    }
};
// @lc code=end
