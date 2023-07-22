/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */
#include <vector>
#include <climits>
#include <functional>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(knlog(n)), s:O(kn)
class Solution
{
public:
    unordered_map<int, int> memo;
    int superEggDrop(int k, int n)
    {
        function<int(int, int)> dp = [&](int k, int n) -> int
        {
            if (n <= 0)
            {
                return 0;
            }
            else if (n == 1)
            {
                return 1;
            }
            if (k == 1)
            {
                return n;
            }
            int key = (n << 7) + k;
            if (memo.count(key))
            {
                return memo[key];
            }
            int left = 0, right = n - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                int val1 = dp(k, n - mid - 1);
                int val2 = dp(k - 1, mid);
                if (val1 > val2)
                {
                    left = mid + 1;
                }
                else if (val1 < val2)
                {
                    right = mid;
                }
                else
                {
                    left = right = mid;
                }
            }
            memo[key] = 1 + max(dp(k - 1, left), dp(k, n - left - 1));
            return memo[key];
        };
        return dp(k, n);
    }
};
// @lc code=end
