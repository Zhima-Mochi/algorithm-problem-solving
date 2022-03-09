/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int arr[101] = {};

public:
    int sumOfUnique(vector<int> &nums)
    {
        for (auto n : nums)
        {
            ++arr[n];
        }
        int res = 0;
        for (int i = 1; i != 101; ++i)
        {
            if (arr[i] == 1)
            {
                res += i;
            }
        }
        return res;
    }
};
// @lc code=end
