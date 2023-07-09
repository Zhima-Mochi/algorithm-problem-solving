/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int largestVariance(string s)
    {
        int w = s.size();
        int res = 0;
        vector<bool> seen(26);
        for (auto c : s)
        {
            seen[c - 'a'] = true;
        }
        for (int i = 0; i != 26; ++i)
        {
            if (!seen[i])
            {
                continue;
            }
            for (int j = 0; j != 26; ++j)
            {
                if (!seen[j])
                {
                    continue;
                }
                if (i == j)
                {
                    continue;
                }
                int cur = 0;
                bool flag = false;
                bool ok = false;
                for (int k = 0; k != w; ++k)
                {
                    if (s[k] - 'a' == i)
                    {
                        cur += 1;
                    }
                    else if (s[k] - 'a' == j)
                    {
                        ok = true;
                        cur -= 1;
                        if (flag)
                        {
                            cur += 1;
                            flag = false;
                        }
                        if (cur < 0)
                        {
                            flag = true;
                            cur = -1;
                        }
                    }
                    if (ok)
                    {
                        res = max(cur, res);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
