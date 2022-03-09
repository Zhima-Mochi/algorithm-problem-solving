/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        unordered_map<int, int> point_count;
        for (auto &rectangle : rectangles)
        {
            for (int i = 0; i < 4; i += 2)
            {
                for (int j = 1; j < 4; j += 2)
                {
                    int val = (rectangle[i] + 100000 << 15) + rectangle[j];
                    int pos = i / 2 + j;
                    if (point_count[val] & (1 << pos - 1))
                    {
                        return false;
                    }
                    else
                    {
                        point_count[val] |= (1 << pos - 1);
                    }
                }
            }
        }
        int count = 0;
        for (auto &p : point_count)
        {
            if (p.second == 1 || p.second == 2 || p.second == 4 || p.second == 8)
            {
                ++count;
                if (count > 4)
                {
                    return false;
                }
            }
            else if (p.second != 3 && p.second != 5 && p.second != 10 && p.second != 12 && p.second != 15)
            {
                return false;
            }
        }
        return count == 4;
    }
};
// @lc code=end
