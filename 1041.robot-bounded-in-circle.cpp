/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{

public:
    bool isRobotBounded(string instructions)
    {
        int hor = 0;
        int ver = 0;
        int ang = 90;
        for (auto c : instructions)
        {
            if (c == 'G')
            {
                if (ang == 90)
                {
                    ver += 1;
                }
                else if (ang == 180)
                {
                    hor -= 1;
                }
                else if (ang == 270)
                {
                    ver -= 1;
                }
                else
                {
                    hor += 1;
                }
            }
            else if (c == 'L')
            {
                ang += 90;
                ang %= 360;
            }
            else
            {
                ang -= 90;
                ang = (ang + 360) % 360;
            }
        }
        return (hor != 0 || ver != 0) && ang == 90 ? false : true;
    }
};
// @lc code=end
