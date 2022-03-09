/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> col_umap(9, vector<bool>(9)), row_umap(9, vector<bool>(9)), square_umap(9, vector<bool>(9));
        int height = board.size();
        int width = board[0].size();
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                char val = board[i][j];
                if (val == '.')
                {
                    continue;
                }
                if (!row_umap[i][val - '1'])
                {
                    row_umap[i][val - '1'] = true;
                }
                else
                {
                    return false;
                }
                if (!col_umap[j][val - '1'])
                {
                    col_umap[j][val - '1'] = true;
                }
                else
                {
                    return false;
                }
                if (!square_umap[3 * (i / 3) + (j / 3)][val - '1'])
                {
                    square_umap[3 * (i / 3) + (j / 3)][val - '1'] = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
