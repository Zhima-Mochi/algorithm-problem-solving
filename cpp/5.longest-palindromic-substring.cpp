/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();

        if (len == 1)
        {
            return s;
        }

        int res = 1;
        pair<int, int> res_pair = {0, 0};

        if (s[0] == s[1])
        {
            res=2;
            res_pair = {0, 1};
        }

        for (int i = 1; (len - i) > res / 2; ++i)
        {
            auto count = 1;
            if (s[i] == s[i + 1])
            {
                auto add = 1;
                while ((i - add >= 0 && i + 1 + add < len) && s[i - add] == s[i + 1 + add])
                {
                    ++add;
                }
                if (res < 2 * add)
                {
                    res = 2 * add;
                    res_pair = {(i - add + 1), i + add};
                }
            }
            if (s[i - 1] == s[i + 1])
            {
                auto add = 1;
                while ((i - add - 1 >= 0 && i + 1 + add < len) && s[i - 1 - add] == s[i + 1 + add])
                {
                    ++add;
                }
                if (res < 2 * add + 1)
                {
                    res = 2 * add + 1;
                    res_pair = {(i - add), i + add};
                }
            }
        }
        return s.substr(res_pair.first, res_pair.second - res_pair.first + 1);
    }
};
// @lc code=end
