/*
 * @lc app=leetcode id=1958 lang=cpp
 *
 * [1958] Check if Move is Legal
 */

#include <vector>
using namespace std;
// @lc code=start
// t:O(m+n), s:O(1)
class Solution
{
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

public:
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
    {
        int h = board.size();
        int w = board[0].size();
        for (auto &dir : dirs)
        {
            int row = rMove;
            int col = cMove;
            char prev = color;
            while (row + dir[0] >= 0 && row + dir[0] < h && col + dir[1] >= 0 && col + dir[1] < w)
            {
                row += dir[0];
                col += dir[1];
                if (board[row][col] == '.')
                {
                    break;
                }
                if (board[row][col] == prev && board[row][col] == color)
                {
                    break;
                }
                if (board[row][col] != prev && board[row][col] == color)
                {
                    return true;
                }
                prev = board[row][col];
            }
        }
        return false;
    }
};
// @lc code=end
