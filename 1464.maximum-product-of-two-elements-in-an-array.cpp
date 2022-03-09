/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> order(2, INT_MIN);
        for (auto n : nums)
        {
            if (n >= order[0])
            {
                order[1] = exchange(order[0], n);
            }
            else if (n > order[1])
            {
                order[1] = n;
            }
        }
        return (order[1] - 1) * (order[0] - 1);
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         auto max_iter = max_element(nums.begin(), nums.end());
//         swap(*max_iter, *(nums.end() - 1));
//         return (*max_element(nums.begin(), nums.end() - 1) - 1) * (nums.back() - 1);
//     }
// };