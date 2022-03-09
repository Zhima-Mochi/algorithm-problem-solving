/*
 * @lc app=leetcode id=2027 lang=cpp
 *
 * [2027] Minimum Moves to Convert String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumMoves(string s)
    {
        int width = s.size();
        int ind = 0;
        int res = 0;
        while (ind < width)
        {
            if (s[ind] == 'X')
            {
                ++res;
                ind += 3;
            }
            else
            {
                ++ind;
            }
        }
        return res;
    }
};
// @lc code=end
