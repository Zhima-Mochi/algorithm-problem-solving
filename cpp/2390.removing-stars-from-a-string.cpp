/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

#include <string>
using namespace std;
// @lc code=start
// t: O(n), s: O(n)
class Solution
{
public:
    string removeStars(string s)
    {
        string res;
        for (auto c : s)
        {
            if (c == '*')
            {
                res.pop_back();
            }
            else
            {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end
