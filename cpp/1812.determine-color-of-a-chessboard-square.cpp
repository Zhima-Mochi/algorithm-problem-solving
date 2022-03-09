/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        return ((coordinates[0] - 'a' + coordinates[1] - '1') % 2);
    }
};
// @lc code=end
