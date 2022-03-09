/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    vector<pair<int, int>> directions = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    double record[26][26][101] = {0};
    int width;

public:
    double knightProbability(int n, int k, int row, int column)
    {
        width = n;
        return helpler(k, row, column);
    }
    double helpler(int k, int r, int c)
    {
        if (k == 0)
        {
            return 1;
        }
        if (record[r][c][k] == 0)
        {
            for (auto &d : directions)
            {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr >= 0 && nr < width && nc >= 0 && nc < width)
                {
                    record[r][c][k] += helpler(k - 1, nr, nc) / 8;
                }
            }
        }
        return record[r][c][k];
    }
};
// @lc code=end
