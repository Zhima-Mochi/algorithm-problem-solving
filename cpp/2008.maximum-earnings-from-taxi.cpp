/*
 * @lc app=leetcode id=2008 lang=cpp
 *
 * [2008] Maximum Earnings From Taxi
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n+m), s:O(n)
class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        int w = rides.size();
        vector<long long> memo(n + 1);
        sort(rides.begin(), rides.end());
        int cur = 0;
        for (int i = 1; i != n + 1; ++i)
        {
            memo[i] = max(memo[i], memo[i - 1]);
            while (cur != w && rides[cur][0] == i)
            {
                memo[rides[cur][1]]=max(memo[rides[cur][1]],memo[i]+rides[cur][1]-rides[cur][0]+rides[cur][2]);
                cur++;
            }
        }
        return memo.back();
    }
};
// @lc code=end
