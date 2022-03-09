/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int magicalString(int n)
    {
        if (n <= 3)
        {
            return 1;
        }
        string s = "122";
        int pos = 2;
        while (s.size() < n)
        {
            s.append(string(s[pos] - '0', s.back() == '1' ? '2' : '1'));
            ++pos;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};
// @lc code=end
