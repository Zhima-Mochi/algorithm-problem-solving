/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        string count = string(26, 0);
        int rest = 26;
        for (auto c : sentence)
        {
            if (count[c - 'a'] == 0)
            {
                count[c - 'a'] |= 1;
                --rest;
                if (rest == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
