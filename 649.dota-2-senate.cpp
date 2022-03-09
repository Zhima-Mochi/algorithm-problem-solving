/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int left_r = 0;
        int left_d = 0;
        int right_r = 0;
        int right_d = 0;
        int width = senate.size();
        for (int i = 0; i != width; ++i)
        {
            if (senate[i] == 'R')
            {
                right_d = max(i, right_d);
                while (right_d != width && senate[right_d] != 'D')
                {
                    ++right_d;
                }
                if (right_d != width)
                {
                    senate[right_d] = 'X';
                }
                else
                {
                    while (left_d < i && senate[left_d] != 'D')
                    {
                        ++left_d;
                    }
                    if (left_d == i)
                    {
                        return "Radiant";
                    }
                    else
                    {
                        senate[left_d++] = 'X';
                    }
                }
            }
            else if (senate[i] == 'D')
            {

                right_r = max(i, right_r);
                while (right_r != width && senate[right_r] != 'R')
                {
                    ++right_r;
                }
                if (right_r != width)
                {
                    senate[right_r] = 'X';
                }
                else
                {
                    while (left_r < i && senate[left_r] != 'R')
                    {
                        ++left_r;
                    }
                    if (left_r == i)
                    {
                        return "Dire";
                    }
                    else
                    {
                        senate[left_r++] = 'X';
                    }
                }
            }
        }
        string next;
        for (auto c : senate)
        {
            if (c != 'X')
            {
                next.push_back(c);
            }
        }
        return predictPartyVictory(next);
    }
};
// @lc code=end