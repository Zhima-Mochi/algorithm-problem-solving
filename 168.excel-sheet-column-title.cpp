/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;
        while (--columnNumber!=-1)
        {
            res.push_back(columnNumber  % 26 + 'A');
            columnNumber /= 26;
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
