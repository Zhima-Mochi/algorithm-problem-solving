/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        int res = 0;
        for (auto c : s)
        {
            res += (c - 'a' + 1) / 10 + (c - 'a' + 1) % 10;
        }
        while (--k)
        {
            int val = 0;
            while (res)
            {
                val += res % 10;
                res /= 10;
            }
            res = val;
        }
        return res;
    }
};
// @lc code=end
