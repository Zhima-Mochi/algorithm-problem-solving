/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canTransform(string start, string end)
    {
        int width = start.size();
        int ind_s = 0, ind_e = 0;
        int x_count = 0;
        while (ind_s != width && ind_e != width)
        {
            if (start[ind_s] == 'X')
            {
                ++ind_s;
                ++x_count;
                continue;
            }
            if (end[ind_e] == 'X')
            {
                ++ind_e;
                --x_count;
                continue;
            }
            if (start[ind_s] != end[ind_e])
            {
                return false;
            }
            else if (start[ind_s] == 'R' && x_count > 0)
            {
                return false;
            }
            else if (start[ind_s] == 'L' && x_count < 0)
            {
                return false;
            }
            ++ind_s;
            ++ind_e;
        }
        while (ind_s != width)
        {
            if (start[ind_s++] != 'X')
            {
                return false;
            }
        }
        while (ind_e != width)
        {
            if (end[ind_e++] != 'X')
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
