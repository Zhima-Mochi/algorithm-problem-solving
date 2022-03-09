/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(len(s)), s:O(n) 
class Solution
{
public:
    bool queryString(string s, int n)
    {
        if (n == 1)
        {
            return s.find('1') != -1;
        }
        int b = 1 << 30;
        while (!(b & n))
        {
            b >>= 1;
        }
        unordered_set<int> collections;
        int val = 0;
        for (auto c : s)
        {
            val *= 2;
            if (c == '1')
            {
                val += 1;
            }
            if (val > n)
            {
                if (val & (b << 1))
                {
                    val &= ~(b << 1);
                }
                else
                {
                    val &= ~b;
                }
            }
            if ((val & b) || (val & (b >> 1)))
            {
                collections.insert(val);
            }
        }
        return collections.size() == (n - (b >> 1) + 1);
    }
};
// @lc code=end
