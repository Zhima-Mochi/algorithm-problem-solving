/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
int MOD = 1000000007;
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int w = s.size();
        vector<int> last_seen(26, -1);
        vector<long long> memo(w + 1);
        for (int i = 1; i <= w; ++i)
        {
            if (last_seen[s[i - 1] - 'a'] == -1)
            {
                memo[i] = memo[i - 1] * 2 + 1;
            }
            else
            {
                memo[i] = memo[i - 1] * 2 - memo[last_seen[s[i - 1] - 'a'] - 1] + MOD;
            }
            memo[i] %= MOD;
            last_seen[s[i - 1] - 'a'] = i;
        }
        return memo[w];
    }
};
// @lc code=end
