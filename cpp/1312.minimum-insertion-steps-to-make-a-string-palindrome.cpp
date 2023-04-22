/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */
#include <string>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t: O(n^2) s: O(1)
class Solution
{
public:
    int minInsertions(string s)
    {
        int w = s.size();
        int records[500][500];
        for (int i = 0; i != w; i++)
        {
            for (int j = 0; j != w; j++)
            {
                records[i][j] = -1;
            }
        }
        function<int(int, int)> dp = [&](int l, int r)
        {
            if (l > r)
            {
                return 0;
            }
            if (records[l][r] != -1)
            {
                return records[l][r];
            }
            if (l == r)
            {
                records[l][r] = 0;
                return 0;
            }
            if (s[l] == s[r])
            {
                records[l][r] = dp(l + 1, r - 1);
            }
            else
            {
                records[l][r] = min({2 + dp(l + 1, r - 1), 1 + dp(l + 1, r), 1 + dp(l, r - 1)});
            }
            return records[l][r];
        };
        return dp(0, w - 1);
    }
};
// @lc code=end
