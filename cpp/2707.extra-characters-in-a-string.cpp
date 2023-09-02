/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> memo;
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int w = s.size();
        memo = vector<int>(w, -1);
        int dw = dictionary.size();
        vector<vector<int>> has_match(w, vector<int>());
        for (int i = 0; i != dw; ++i)
        {
            int cur = 0;
            int w_sz = dictionary[i].size();
            while (cur != w)
            {
                cur = s.find(dictionary[i], cur);
                if (cur != -1)
                {
                    has_match[cur].push_back(w_sz);
                }
                else
                {
                    break;
                }
                cur += 1;
            }
        }
        return dfs(has_match, w, 0);
    }
    int dfs(vector<vector<int>> &has_match, int w, int pos)
    {
        if (pos == w)
        {
            return 0;
        }
        if (memo[pos] != -1)
        {
            return memo[pos];
        }
        int res = 1 + dfs(has_match, w, pos + 1);
        for (auto len : has_match[pos])
        {
            res = min(res, dfs(has_match, w, pos + len));
        }
        memo[pos] = res;
        return res;
    }
};
// @lc code=end
