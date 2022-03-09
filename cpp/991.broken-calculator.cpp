/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */
#include <unordered_map>
#include <climits>
using namespace std;
// @lc code=start
// t:O(log(target)), s:O(1)
class Solution
{
    int start_value;

public:
    int brokenCalc(int startValue, int target)
    {
        start_value = startValue;
        return dfs(target);
    }
    int dfs(int n)
    {
        if (n == start_value)
        {
            return 0;
        }
        return n % 2 == 0 && n > start_value ? 1 + dfs(n / 2) : n < start_value ? start_value - n
                                                                                : 1 + dfs(n + 1);
    }
};
// @lc code=end
