/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> direction = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    int height;
    int width;

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        height = board.size();
        width = board[0].size();
        dfs(board, click);
        return board;
    }
    void dfs(vector<vector<char>> &board, const vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
        }
        else if (board[click[0]][click[1]] == 'E')
        {
            int mines = 0;
            for (const auto &d : direction)
            {
                vector<int> new_pos = {click[0] + d[0], click[1] + d[1]};
                if (new_pos[0] < 0 || new_pos[0] >= height || new_pos[1] < 0 || new_pos[1] >= width)
                {
                    continue;
                }
                if (board[new_pos[0]][new_pos[1]] == 'M')
                {
                    ++mines;
                }
            }
            if (mines > 0)
            {
                board[click[0]][click[1]] = '0' + mines;
            }
            else
            {
                board[click[0]][click[1]] = 'B';
                for (const auto &d : direction)
                {
                    vector<int> new_pos = {click[0] + d[0], click[1] + d[1]};
                    if (new_pos[0] < 0 || new_pos[0] >= height || new_pos[1] < 0 || new_pos[1] >= width)
                    {
                        continue;
                    }
                    if (board[new_pos[0]][new_pos[1]] == 'E')
                    {
                        dfs(board, new_pos);
                    }
                }
            }
        }
    }
};
// @lc code=end
