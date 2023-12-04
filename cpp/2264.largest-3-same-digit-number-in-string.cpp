/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        int n = num.size();
        for (int i = 2; i != n; ++i)
        {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2])
            {
                if (ans == "" || ans[0] < num[i])
                {
                    ans = num.substr(i - 2, 3);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
