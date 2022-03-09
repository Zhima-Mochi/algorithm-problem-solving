/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int pos = 0;
        unordered_set<int> seen;
        seen.insert(0);
        for (auto c : path)
        {
            if (c == 'N')
            {
                pos += 1;
            }
            else if (c == 'S')
            {
                pos -= 1;
            }
            else if (c == 'E')
            {
                pos += 1 << 14;
            }
            else
            {
                pos -= 1 << 14;
            }
            if (seen.count(pos))
            {
                return true;
            }
            else
            {
                seen.insert(pos);
            }
        }
        return false;
    }
};
// @lc code=end
