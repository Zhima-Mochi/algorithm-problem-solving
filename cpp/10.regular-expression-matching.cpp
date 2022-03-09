/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(len(s)*len(p)), s:O(len(s)*len(p))
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int ws = s.size(), wp = p.size();
        vector<vector<int>> records(ws + 1, vector<int>(wp + 1, -1));
        function<bool(int, int)> dp = [&](int sd, int pd)
        {
            if (pd == wp && sd == ws)
            {
                return true;
            }
            else if (pd == wp)
            {
                return false;
            }
            if (records[sd][pd] != -1)
            {
                return records[sd][pd] == 1;
            }

            if (pd < wp - 1 && p[pd + 1] == '*')
            {
                if (p[pd] == '.')
                {
                    for (int i = sd; i != ws + 1; ++i)
                    {
                        if (dp(i, pd + 2))
                        {
                            return (records[sd][pd] = 1) == 1;
                        }
                    }
                }
                else
                {
                    if (dp(sd, pd + 2))
                    {
                        return true;
                    }
                    for (int i = sd; i != ws; ++i)
                    {
                        if (s[i] != p[pd])
                        {
                            break;
                        }
                        if (dp(i + 1, pd + 2))
                        {
                            return (records[sd][pd] = 1) == 1;
                        }
                    }
                }
            }
            else if (sd != ws && s[sd] != p[pd] && p[pd] != '.')
            {
                return (records[sd][pd] = 0) == 1;
            }
            else if (sd == ws && (pd >= wp - 1 || p[pd] != '.' || p[pd + 1] != '*'))
            {
                return (records[sd][pd] = 0) == 1;
            }
            else if (sd != ws)
            {
                return dp(sd + 1, pd + 1);
            }
            return (records[sd][pd] = 0) == 1;
        };
        return dp(0, 0);
    }
};
// @lc code=end
