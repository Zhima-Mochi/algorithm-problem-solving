/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string generateTheString(int n)
    {
        if (n % 2)
        {
            return string(n, 'a');
        }
        else
        {
            return string(n - 1, 'a') + 'b';
        }
    }
};
// @lc code=end
