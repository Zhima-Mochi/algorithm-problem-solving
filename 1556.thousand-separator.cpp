/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string thousandSeparator(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        string res;
        int iter_time = 0;
        while (n)
        {
            res.push_back('0' + n % 10);
            ++iter_time;
            n /= 10;
            if (n && iter_time % 3 == 0)
            {
                res.push_back('.');
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
