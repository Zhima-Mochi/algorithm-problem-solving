/*
 * @lc app=leetcode id=782 lang=cpp
 *
 * [782] Transform to Chessboard
 */
#include <vector>
#include <bitset>
#include <array>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int width;

public:
    int movesToChessboard(vector<vector<int>> &board)
    {
        width = board[0].size();
        for (int i = 1; i != width; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                if (board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j])
                {
                    return -1;
                }
            }
        }
        array<int, 2> row_count, col_count;
        row_count.fill(0);
        col_count.fill(0);
        for (int i = 0; i != width; ++i)
        {
            if (board[0][i])
            {
                ++row_count[i % 2];
            }
            if (board[i][0])
            {
                ++col_count[i % 2];
            }
        }
        int res = 0;
        if (width % 2)
        {
            if (row_count[0] + row_count[1] < width / 2 || row_count[0] + row_count[1] > width / 2 + 1)
            {
                return -1;
            }
            if (col_count[0] + col_count[1] < width / 2 || col_count[0] + col_count[1] > width / 2 + 1)
            {
                return -1;
            }
            if (row_count[0] + row_count[1] == width / 2)
            {
                res += row_count[0];
            }
            else
            {
                res += row_count[1];
            }
            if (col_count[0] + col_count[1] == width / 2)
            {
                res += col_count[0];
            }
            else
            {
                res += col_count[1];
            }
        }
        else
        {
            if (row_count[0] + row_count[1] != width / 2)
            {
                return -1;
            }
            if (col_count[0] + col_count[1] != width / 2)
            {
                return -1;
            }
            res += min(row_count[0], row_count[1]);
            res += min(col_count[0], col_count[1]);
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
//     int width;
//     int height;
//     unordered_map<bitset<30>, array<int, 2>> umap_row;
//     unordered_map<bitset<30>, array<int, 2>> umap_col;

// public:
//     int movesToChessboard(vector<vector<int>> &board)
//     {
//         height = board.size();
//         width = board[0].size();
//         if (rowToB(board) && colToB(board))
//         {
//             return swap_times(umap_row, height) + swap_times(umap_col, width);
//         }
//         return -1;
//     }
//     bool rowToB(vector<vector<int>> &board)
//     {
//         for (int i = 0; i != height; ++i)
//         {
//             bitset<30> res;
//             for (int j = 0; j != width; ++j)
//             {
//                 if (board[i][j])
//                 {
//                     res.set(j);
//                 }
//             }
//             if (umap_row.count(res) == 0)
//             {
//                 umap_row[res].fill(0);
//             }
//             ++umap_row[res][i % 2];
//             if (umap_row.size() > 2)
//             {
//                 return false;
//             }
//             if (umap_row[res][0] + umap_row[res][1] > (height + 1) / 2)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool colToB(vector<vector<int>> &board)
//     {
//         for (int j = 0; j != width; ++j)
//         {
//             bitset<30> res;
//             for (int i = 0; i != height; ++i)
//             {
//                 if (board[i][j])
//                 {
//                     res.set(i);
//                 }
//             }
//             if (umap_col.count(res) == 0)
//             {
//                 umap_col[res].fill(0);
//             }
//             ++umap_col[res][j % 2];
//             if (umap_col.size() > 2)
//             {
//                 return false;
//             }
//             if (umap_col[res][0] + umap_col[res][1] > (width + 1) / 2)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     int swap_times(unordered_map<bitset<30>, array<int, 2>> &umap, int len)
//     {
//         int res = 0;
//         if (len % 2 == 0)
//         {
//             res = min(umap.begin()->second[0], umap.begin()->second[1]);
//         }
//         else
//         {
//             int count = 0;
//             for (auto &p : umap)
//             {
//                 if (p.second[0] + p.second[1] > count)
//                 {
//                     count = p.second[0] + p.second[1];
//                     res = p.second[1];
//                 }
//             }
//         }
//         return res;
//     }
// };