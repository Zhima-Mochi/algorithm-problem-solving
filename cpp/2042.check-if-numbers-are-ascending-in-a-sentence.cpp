/*
 * @lc app=leetcode id=2042 lang=cpp
 *
 * [2042] Check if Numbers Are Ascending in a Sentence
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int prev = 0;
        int val = 0;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                val *= 10;
                val += c - '0';
            }
            else if (isblank(c))
            {
                if (val != 0)
                {
                    if (prev >= val)
                    {
                        return false;
                    }
                    else
                    {
                        prev = val;
                        val = 0;
                    }
                }
            }
        }
        if (val == 0)
        {
            return true;
        }
        else
        {
            return val > prev;
        }
    }
};
// @lc code=end
