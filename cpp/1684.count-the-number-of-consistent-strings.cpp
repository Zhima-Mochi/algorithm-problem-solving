/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int res = 0;
        for (auto &s : words)
        {
            if (s.find_first_not_of(allowed) == -1)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
