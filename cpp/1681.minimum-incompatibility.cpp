/*
 * @lc app=leetcode id=1681 lang=cpp
 *
 * [1681] Minimum Incompatibility
 */
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumIncompatibility(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> memo(1 << n, INT_MAX);
        memo[0] = 0;
        int group = n / k;
        unordered_map<int, int> values;

        for (int mask = 1; mask < (1 << n); mask++)
        {
            if (__builtin_popcount(mask) != group)
            {
                continue;
            }
            int mn = 20, mx = 0;
            vector<bool> seen(n + 1);
            int seen_cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    if (seen[nums[i]] > 0)
                    {
                        break;
                    }
                    seen[nums[i]];
                    seen_cnt++;
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            if (seen_cnt == group)
            {
                values[mask] = mx - mn;
            }
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (memo[mask] == INT_MAX)
            {
                continue;
            }
            unordered_map<int, int> seen;
            for (int i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) == 0)
                {
                    seen[nums[i]] = i;
                }
            }
            if (seen.size() < group)
            {
                continue;
            }
            int sub = 0;
            for (auto &pair : seen)
            {
                sub |= (1 << pair.second);
            }
            int nxt = sub;
            while (nxt > 0)
            {
                if (values.count(nxt) > 0)
                {
                    memo[mask | nxt] = min(memo[mask | nxt], memo[mask] + values[nxt]);
                }
                nxt = (nxt - 1) & sub;
            }
        }

        return (memo[(1 << n) - 1] < INT_MAX) ? memo[(1 << n) - 1] : -1;
    }
};
// @lc code=end
