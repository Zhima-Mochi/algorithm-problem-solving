/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    int countBattleships(vector<vector<char>> &board)
    {
        height = board.size();
        width = board[0].size();
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (board[i][j] == 'X' && (j == 0 || board[i][j - 1] == '.') && (i == 0 || board[i - 1][j] == '.'))
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
//     int height;
//     int width;

// public:
//     int countBattleships(vector<vector<char>> &board)
//     {
//         height = board.size();
//         width = board[0].size();
//         int res = 0;
//         for (int i = 0; i != height; ++i)
//         {
//             for (int j = 0; j != width; ++j)
//             {
//                 if (board[i][j] == 'X')
//                 {
//                     dfs(board, res, i, j, 0);
//                 }
//             }
//         }
//         return res;
//     }
//     void dfs(vector<vector<char>> &board, int &res, int row, int col, int type)
//     {
//         if (row >= height || col >= width || board[row][col] == '.')
//         {
//             return;
//         }
//         if (type == 0)
//         {
//             board[row][col] = '.';
//             bool v = row + 1 < height && board[row + 1][col] == 'X';
//             bool h = col + 1 < width && board[row][col + 1] == 'X';
//             if (v && h)
//             {
//                 res += 2;
//                 dfs(board, res, row + 1, col, 1);
//                 dfs(board, res, row, col + 1, 2);
//             }
//             else if (v)
//             {
//                 res += 1;
//                 dfs(board, res, row + 1, col, 1);
//             }
//             else if (h)
//             {
//                 res += 1;
//                 dfs(board, res, row, col + 1, 2);
//             }
//             else
//             {
//                 res += 1;
//             }
//         }
//         else if (type == 1)
//         {
//             if (col + 1 < width && board[row][col + 1] == 'X')
//             {
//                 return;
//             }
//             else
//             {
//                 board[row][col] = '.';
//                 dfs(board, res, row + 1, col, 1);
//             }
//         }
//         else
//         {
//             if (row + 1 < height && board[row + 1][col] == 'X')
//             {
//                 return;
//             }
//             else
//             {
//                 board[row][col] = '.';
//                 dfs(board, res, row, col + 1, 2);
//             }
//         }
//     }
// };