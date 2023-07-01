/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */
#include <vector>
#include <functional>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        int cookie_w = cookies.size();
        if (cookie_w == k)
        {
            return *max_element(cookies.begin(), cookies.end());
        }
        vector<int> memo(k, 0);
        int res = 1000000;
        function<void(int)> dfs = [&](int cookie)
        {
            if (cookie == cookie_w)
            {
                int mx = *max_element(memo.begin(), memo.end());
                res = min(res, mx);
                return;
            }
            for (int i = 0; i != k; ++i)
            {
                if (memo[i] + cookies[cookie] >= res)
                {
                    continue;
                }
                memo[i] += cookies[cookie];
                dfs(cookie + 1);
                memo[i] -= cookies[cookie];
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end
