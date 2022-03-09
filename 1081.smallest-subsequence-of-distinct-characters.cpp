/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> last_seen(26, -1);
        int w = s.size();
        for (int i = 0; i != w; ++i)
        {
            last_seen[s[i] - 'a'] = i;
        }
        string res = "";
        vector<bool> seen(26);
        for (int i = 0; i != w; ++i)
        {
            char c = s[i];
            if (!seen[c - 'a'])
            {
                while (!res.empty() && c < res.back() && last_seen[res.back() - 'a'] > i)
                {
                    seen[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                seen[c - 'a'] = true;
            }
        }
        return res;
    }
};
// @lc code=end
