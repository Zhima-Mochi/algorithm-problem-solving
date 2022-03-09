/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int v = 0;
        int h = 0;
        if (moves.size() % 2)
        {
            return false;
        }
        for (auto w : moves)
        {
            switch (w)
            {
            case 'U':
                v++;
                break;
            case 'D':
                v--;
                break;
            case 'R':
                h++;
                break;
            case 'L':
                h--;
                break;
            }
        }
        return v == 0 && h == 0;
    }
};
// @lc code=end
