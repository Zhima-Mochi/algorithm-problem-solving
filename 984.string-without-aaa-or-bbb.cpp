/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(a+b), s:O(a+b)
class Solution
{
    string repeat(string s, int times)
    {
        string res = "";
        res.reserve(s.size() * times);
        while (times--)
        {
            res += s;
        }
        return res;
    }

public:
    string strWithout3a3b(int a, int b)
    {
        if (a >= b)
        {
            int val1 = min(a - min(a, b),b);
            int val2 = min(a - 2 * val1, b - val1);
            int val3 = a - 2 * val1 - val2;
            int val4 = b - val1 - val2;
            return repeat("aab", val1) + repeat("ab", val2) + string(val3, 'a') + string(val4, 'b');
        }
        else
        {
            int val1 = min(b - min(a, b),a);
            int val2 = min(b - 2 * val1, a - val1);
            int val3 = b - 2 * val1 - val2;
            int val4 = a - val1 - val2;
            return repeat("bba", val1) + repeat("ba", val2) + string(val3, 'b') + string(val4, 'a');
        }
    }
};
// @lc code=end
