/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        res.reserve(queries.size());
        int w = pattern.size();
        for (auto &s : queries)
        {
            int idx = 0;
            bool flag = true;
            for (auto c : s)
            {
                if (isupper(c))
                {
                    if (idx == w || c != pattern[idx++])
                    {
                        flag = false;
                        break;
                    }
                }
                else if (idx != w && c == pattern[idx])
                {
                    ++idx;
                }
            }
            flag = flag && idx == w;
            res.push_back(flag);
        }
        return res;
    }
};
// @lc code=end
