/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res = {vector<string>({s.substr(0, 1)})};
        int len = s.size();
        if (len == 1)
        {
            return res;
        }
        for (int i = 1; i != len; ++i)
        {
            int sub_len = res.size();
            for (int j = 0; j != sub_len; ++j)
            {
                if (res[j].back() == s.substr(i, 1))
                {
                    res.push_back(res[j]);
                    res.back().back().push_back(s[i]);
                }
                if (res[j].size() > 1 && res[j][res[j].size() - 2] == s.substr(i, 1))
                {
                    res.push_back(res[j]);
                    auto new_one=s[i]+res.back().back()+s[i];
                    res.back().pop_back();
                    res.back().pop_back();
                    res.back().push_back(new_one);
                }
                res[j].push_back(s.substr(i,1));
            }
        }
        return res;
    }
};
// @lc code=end
