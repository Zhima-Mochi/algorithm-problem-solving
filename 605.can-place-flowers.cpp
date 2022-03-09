/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        auto pos = flowerbed.begin();
        auto end_pos = flowerbed.end();
        auto len = flowerbed.size();
        while (n)
        {
            if (pos == end_pos)
            {
                break;
            }
            if (pos + 1 == end_pos)
            {
                if (*pos == 0)
                {
                    --n;
                }
                break;
            }
            if (*pos == 0 && *(pos + 1) == 0)
            {
                --n;
                pos = pos + 2;
            }
            else
            {
                pos = find(pos + 1, end_pos, 0);
                if (pos == end_pos)
                {
                    break;
                }
                pos += 1;
            }
        }
        return n == 0;
    }
};
// @lc code=end
