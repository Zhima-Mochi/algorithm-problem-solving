/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minLength(string s)
    {
        string ans;
        for (auto c : s)
        {
            ans.push_back(c);
            while (ans.size() >= 2)
            {
                auto t = ans.substr(ans.size() - 2);
                if (t == "AB" || t == "CD")
                {
                    ans.erase(ans.size() - 2);
                }
                else
                {
                    break;
                }
            }
        }
        return ans.size();
    }
};
// @lc code=end
