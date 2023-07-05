/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n*d), s:O(n)
class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        int w = arr.size();
        vector<int> memo(w, -1);
        function<int(int)> dp = [&](int pos) -> int
        {
            if (memo[pos] != -1)
            {
                return memo[pos];
            }
            int res = 1;
            for (int i = 1; i <= d; i++)
            {
                if (pos + i >= w || arr[pos + i] >= arr[pos])
                {
                    break;
                }
                res = max(dp(pos + i) + 1, res);
            }
            for (int i = 1; i <= d; i++)
            {
                if (pos - i < 0 || arr[pos - i] >= arr[pos])
                {
                    break;
                }
                res = max(dp(pos - i) + 1, res);
            }
            memo[pos] = res;
            return res;
        };
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            res = max(res, dp(i));
        }
        return res;
    }
};
// @lc code=end
