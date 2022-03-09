/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> colors = vector<int>(26, -1);
    int find_root_color(int alpha)
    {
        if (colors[alpha] == -1)
        {
            return -1;
        }
        else if (colors[alpha] == alpha)
        {
            return alpha;
        }
        else
        {
            return colors[alpha] = find_root_color(colors[alpha]);
        }
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        for (auto &equ : equations)
        {
            if (equ[1] == '=')
            {
                int color1 = find_root_color(equ[0] - 'a');
                int color2 = find_root_color(equ[3] - 'a');
                if (color1 == -1 && color2 == -1)
                {
                    colors[equ[3] - 'a'] = colors[equ[0] - 'a'] = equ[0] - 'a';
                }
                else if (color1 == -1)
                {
                    colors[equ[0] - 'a'] = color2;
                }
                else if (color2 == -1)
                {
                    colors[equ[3] - 'a'] = color1;
                }
                else
                {
                    colors[color2] = color1;
                }
            }
        }
        for (auto &equ : equations)
        {
            if (equ[1] == '!')
            {
                if (equ[0] == equ[3])
                {
                    return false;
                }
                int color1 = find_root_color(equ[0] - 'a');
                int color2 = find_root_color(equ[3] - 'a');
                if (color1 != -1 && color2 != -1)
                {
                    if (color1 == color2)
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
