/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        if (height == width)
        {
            for (int i = 0; i != height; ++i)
            {
                for (int j = i + 1; j != width; ++j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            return matrix;
        }
        else
        {
            vector<vector<int>> res(width, vector<int>(height));
            for (int i = 0; i != height; ++i)
            {
                for (int j = 0; j != width; ++j)
                {
                    res[j][i] = matrix[i][j];
                }
            }
            return res;
        }
    }
};
// @lc code=end
