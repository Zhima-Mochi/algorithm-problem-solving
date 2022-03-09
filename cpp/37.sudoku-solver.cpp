/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    using coordinate = pair<int, int>;
    vector<bitset<9>> col_umap, row_umap, square_umap;

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        int height = board.size();
        int width = board[0].size();
        col_umap = row_umap = square_umap = vector<bitset<9>>(9);

        hasNumberSudoku(board);
        vector<coordinate> unsolved_pos;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                char val = board[i][j];
                if (val == '.')
                {
                    unsolved_pos.push_back({i, j});
                }
            }
        }
        auto comp = [this](const coordinate &l, const coordinate &r)
        {
            return candidateCount(l).count() >= candidateCount(r).count();
        };
        sort(unsolved_pos.begin(), unsolved_pos.end(), comp);
        dfs(board, unsolved_pos);
    }
    bool dfs(vector<vector<char>> &board, vector<coordinate> &unsolved_pos)
    {
        if (unsolved_pos.empty())
        {
            return true;
        }
        auto coordi = unsolved_pos.back();
        unsolved_pos.pop_back();
        auto candidate = candidateCount(coordi);
        for (int i = 0; i != 9; ++i)
        {
            if (candidate[i] == true)
            {
                board[coordi.first][coordi.second] = '1' + i;
                row_umap[coordi.first][i] = true;
                col_umap[coordi.second][i] = true;
                square_umap[3 * (coordi.first / 3) + (coordi.second / 3)][i] = true;
                if (dfs(board, unsolved_pos))
                {
                    return true;
                }
                row_umap[coordi.first][i] = false;
                col_umap[coordi.second][i] = false;
                square_umap[3 * (coordi.first / 3) + (coordi.second / 3)][i] = false;
            }
        }
        unsolved_pos.push_back(coordi);
        return false;
    }
    bitset<9> candidateCount(const coordinate &coord)
    {
        auto bs = row_umap[coord.first];
        bs |= col_umap[coord.second];
        bs |= square_umap[3 * (coord.first / 3) + (coord.second / 3)];
        bs.flip();
        return bs;
    };

    void hasNumberSudoku(vector<vector<char>> &board)
    {
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
                    return;
                }
                if (!col_umap[j][val - '1'])
                {
                    col_umap[j][val - '1'] = true;
                }
                else
                {
                    return;
                }
                if (!square_umap[3 * (i / 3) + (j / 3)][val - '1'])
                {
                    square_umap[3 * (i / 3) + (j / 3)][val - '1'] = true;
                }
                else
                {
                    return;
                }
            }
        }
    }
};
// @lc code=end
