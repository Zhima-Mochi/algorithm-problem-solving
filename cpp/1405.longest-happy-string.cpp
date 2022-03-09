/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string abc = "abc";
        vector<int> cnt = {a, b, c};
        string res;
        sort(abc.begin(), abc.end(), [&](char l, char r)
             { return cnt[l - 'a'] > cnt[r - 'a']; });
        if (cnt[abc[0] - 'a'] > 0)
        {
            int val1 = min(cnt[abc[0] - 'a'], 2);
            cnt[abc[0] - 'a'] -= val1;
            if (cnt[abc[1] - 'a'] > 0)
            {
                int val2 = cnt[abc[0] - 'a'] >= cnt[abc[1] - 'a'] ? 1 : 0;
                cnt[abc[1] - 'a'] -= val2;
                res += string(val1, abc[0]) + string(val2, abc[1]) + longestDiverseString(cnt[0], cnt[1], cnt[2]);
            }
            else
            {
                res += string(val1, abc[0]);
            }
        }
        return res;
    }
};
// @lc code=end
