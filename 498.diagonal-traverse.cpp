/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> res;
        int height = mat.size(), width = mat[0].size();
        int row = 0, col = 0;
        bool upperward = true;
        while (row < height && col < width)
        {
            res.push_back(mat[row][col]);
            if (upperward)
            {
                if (row > 0 && col < width - 1)
                {
                    --row;
                    ++col;
                }
                else if (col == width - 1)
                {
                    upperward = false;
                    ++row;
                }
                else if (row == 0)
                {
                    upperward = false;
                    ++col;
                }
            }
            else
            {
                if (row < height - 1 && col > 0)
                {
                    ++row;
                    --col;
                }
                else if (row == height - 1)
                {
                    upperward = true;
                    ++col;
                }
                else if (col == 0)
                {
                    upperward = true;
                    ++row;
                }
            }
        }
        return res;
    }
};
// @lc code=end
