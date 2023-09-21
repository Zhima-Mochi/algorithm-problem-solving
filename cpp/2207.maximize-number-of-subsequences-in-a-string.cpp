/*
 * @lc app=leetcode id=2207 lang=cpp
 *
 * [2207] Maximize Number of Subsequences in a String
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int cnt2 = 0;
        int cnt1 = 0;
        for (char t : text)
        {
            if (t == pattern[1])
            {
                cnt2++;
            }
            else if (t == pattern[0])
            {
                cnt1++;
            }
        }
        long long res = max(cnt2, cnt1);
        for (char c : text)
        {
            if (c == pattern[1])
            {
                cnt2 -= 1;
            }
            if (c == pattern[0])
            {
                res += cnt2;
            }
            if (cnt2 == 0)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
