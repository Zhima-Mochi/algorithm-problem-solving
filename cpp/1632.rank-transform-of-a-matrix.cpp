/*
 * @lc app=leetcode id=1632 lang=cpp
 *
 * [1632] Rank Transform of a Matrix
 */
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<array<int, 2>> matrix_list;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                matrix_list.push_back({matrix[i][j], i + (j << 12)});
            }
        }
        sort(matrix_list.begin(), matrix_list.end(), [](array<int, 2> &l, array<int, 2> &r)
             { return l[0] < r[0]; });
        int prev_val = INT_MIN;
        vector<int> col_order(width, 0);
        vector<int> row_order(height, 0);
        vector<int> same_val_pos;
        for (auto &elem : matrix_list)
        {
            if (elem[0] != prev_val)
            {
                helpler(matrix, col_order, row_order, same_val_pos);
                prev_val = elem[0];
                same_val_pos.clear();
            }
            same_val_pos.push_back(elem[1]);
        }
        helpler(matrix, col_order, row_order, same_val_pos);
        return matrix;
    }
    void helpler(vector<vector<int>> &matrix, vector<int> &col_order, vector<int> &row_order, vector<int> &same_val_pos)
    {
        auto order2 = vector<int>(row_order.size() + col_order.size(), -1);
        for (auto &elem : same_val_pos)
        {
            int row_ind = elem & 0xFFF;
            int col_ind = elem >> 12;
            auto i = backwardFind(order2, row_ind);
            auto j = backwardFind(order2, col_ind + row_order.size());
            if (i != j)
            {
                order2[i] = min({order2[i], order2[j], -(max(row_order[row_ind], col_order[col_ind]) + 1)});
                order2[j] = i;
            }
        }
        for (auto &elem : same_val_pos)
        {
            int row_ind = elem & 0xFFF;
            int col_ind = elem >> 12;
            matrix[row_ind][col_ind] = row_order[row_ind] = col_order[col_ind] = -order2[backwardFind(order2, row_ind)];
        }
    }
    int backwardFind(vector<int> &order, int ind)
    {
        if (order[ind] < 0)
        {
            return ind;
        }
        else
        {
            return order[ind] = backwardFind(order, order[ind]);
        }
    }
};
// @lc code=end
