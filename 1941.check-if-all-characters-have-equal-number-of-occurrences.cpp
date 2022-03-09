/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        string count(26, 0);
        for (auto c : s)
        {
            ++count[c - 'a'];
        }
        int num = 0;
        for (auto n : count)
        {
            if (n != 0)
            {
                if (num == 0)
                {
                    num = n;
                }
                else
                {
                    if (num != n)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
