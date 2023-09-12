/*
 * @lc app=leetcode id=2311 lang=cpp
 *
 * [2311] Longest Binary Subsequence Less Than or Equal to K
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int w = s.size();
        int res = 0;
        int cur = 0;
        long long val = 0;
        for (auto c : s)
        {
            val <<= 1;
            cur += 1;
            if (c == '1')
            {
                val += 1;
            }
            while (val > k)
            {
                val = deleteFirstBit(val);
                cur -= 1;
            }
            res = max(res, cur);
        }
        return res;
    }
    long long deleteFirstBit(long long val)
    {
        int pos = 0;

        while ((1LL << (pos + 1)) <= val)
        {
            pos += 1;
        }
        return val - (1 << pos);
    }
};
// @lc code=end
