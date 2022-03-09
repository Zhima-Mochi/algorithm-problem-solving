/*
 * @lc app=leetcode id=2068 lang=cpp
 *
 * [2068] Check Whether Two Strings are Almost Equivalent
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        vector<int> record(26);
        for (auto w : word1)
        {
            ++record[w - 'a'];
        }
        for (auto w : word2)
        {
            --record[w - 'a'];
        }
        for (auto n : record)
        {
            if (n > 3 || n < -3)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
