/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int helper(int num)
    {
        int res = 0;
        while (num)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int maximumSum(vector<int> &nums)
    {
        int res = -1;
        unordered_map<int, int> digit_max;
        for (auto num : nums)
        {
            int d = helper(num);
            if (digit_max.count(d))
            {
                res = max(digit_max[d] + num, res);
            }
            digit_max[d] = max(digit_max[d], num);
        }
        return res;
    }
};
// @lc code=end
