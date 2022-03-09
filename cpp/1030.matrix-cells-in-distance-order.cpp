/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        int len = max(rCenter, rows - 1 - rCenter) + max(cCenter, cols - 1 - cCenter);
        vector<int> count(len + 1);
        for (int i = 0; i != rows; ++i)
        {
            for (int j = 0; j != cols; ++j)
            {
                ++count[abs(rCenter - i) + abs(cCenter - j)];
            }
        }
        for (int i = 1; i != len + 1; ++i)
        {
            count[i] += count[i - 1];
        }
        vector<vector<int>> res(count.back());
        for (int i = 0; i != rows; ++i)
        {
            for (int j = 0; j != cols; ++j)
            {
                auto pos = --count[abs(rCenter - i) + abs(cCenter - j)];
                res[pos] = {i, j};
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
//     {
//         vector<vector<int>> res;
//         vector<vector<bool>> dp(rows, vector<bool>(cols));
//         dp[rCenter][cCenter] = true;
//         queue<vector<int>> pos;
//         pos.push({rCenter, cCenter});
//         while (!pos.empty())
//         {
//             int pos_len = pos.size();
//             while (pos_len--)
//             {
//                 auto p = pos.front();
//                 pos.pop();
//                 res.push_back(p);
//                 if (p[0] + 1 != rows && !dp[p[0] + 1][p[1]])
//                 {
//                     pos.push({p[0] + 1, p[1]});
//                     dp[p[0] + 1][p[1]] = true;
//                 }
//                 if (p[0] - 1 != -1 && !dp[p[0] - 1][p[1]])
//                 {
//                     pos.push({p[0] - 1, p[1]});
//                     dp[p[0] - 1][p[1]] = true;
//                 }
//                 if (p[1] + 1 != cols && !dp[p[0]][p[1] + 1])
//                 {
//                     pos.push({p[0], p[1] + 1});
//                     dp[p[0]][p[1] + 1] = true;
//                 }
//                 if (p[1] - 1 != -1 && !dp[p[0]][p[1] - 1])
//                 {
//                     pos.push({p[0], p[1] - 1});
//                     dp[p[0]][p[1] - 1] = true;
//                 }
//             }
//         }
//         return res;
//     }
// };