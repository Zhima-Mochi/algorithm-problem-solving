/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        for (int pos = 0; pos + k - 1 < len; pos += 2 * k)
            reverse(s.begin() + pos, s.begin() + pos + k);
        if (len % (2 * k) < k)
            reverse(s.end() - len % (2 * k), s.end());
        return s;
    }
};
// @lc code=end
