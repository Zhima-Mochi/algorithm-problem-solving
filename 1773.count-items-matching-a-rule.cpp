/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int key_val;
        if (ruleKey == "type")
        {
            key_val = 0;
        }
        else if (ruleKey == "color")
        {
            key_val = 1;
        }
        else
        {
            key_val = 2;
        }
        int res = 0;
        for (auto &elem : items)
        {
            if (elem[key_val] == ruleValue)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
