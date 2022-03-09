/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int res = 0;
        int width = colors.size();
        for (int i = 0; i != width - 1; ++i)
        {
            for (int j = i + 1; j != width; ++j)
            {
                if (colors[i] != colors[j])
                {
                    res = max(res, j - i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int maxDistance(vector<int> &colors)
//     {
//         vector<int> leftmost_pos(101, -1);
//         int width = colors.size();
//         int res = 0;
//         for (int i = 0; i != width; ++i)
//         {
//             if (leftmost_pos[colors[i]] == -1)
//             {
//                 leftmost_pos[colors[i]] = i;
//             }
//             if ((i < width - 1 && colors[i + 1] != colors[i]) || i == width - 1)
//             {
//                 for (int c = 0; c != 101; ++c)
//                 {
//                     if (c != colors[i] && leftmost_pos[c] != -1)
//                     {
//                         res = max(res, i - leftmost_pos[c]);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };
