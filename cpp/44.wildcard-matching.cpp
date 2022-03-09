/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include <string>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_len = s.size(), p_len = p.size();
        // function<bool(int, int)> dp = [&](int si, int pi)
        // {
        //     if (si < -1 || pi < -1)
        //     {
        //         return false;
        //     }
        //     if (si == -1 && pi == -1)
        //     {
        //         return true;
        //     }
        //     else if (pi == -1)
        //     {
        //         return false;
        //     }
        //     if (si >= 0 && (s[si] == p[pi] || p[pi] == '?'))
        //     {
        //         return dp(si - 1, pi - 1);
        //     }
        //     if (p[pi] == '*')
        //     {
        //         return dp(si - 1, pi) || dp(si, pi - 1);
        //     }
        //     return false;
        // };
        vector<bool> records(s_len + 1);
        records[0] = true;
        for (int pi = 0; pi != p_len; ++pi)
        {
            bool prev = records[0];
            records[0] = p[pi] == '*' && records[0];
            for (int si = 0; si != s_len; ++si)
            {
                bool next_prev = records[si + 1];
                if (s[si] == p[pi] || p[pi] == '?')
                {
                    records[si + 1] = prev;
                }
                else if (p[pi] == '*')
                {
                    records[si + 1] = records[si + 1] || records[si];
                }
                else
                {
                    records[si + 1] = false;
                }
                prev = next_prev;
            }
        }
        return records.back();
    }
};
// @lc code=end
