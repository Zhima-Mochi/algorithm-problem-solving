/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int side_length = mat.size();
        int res = 0;
        for (int i = 0; i != side_length; ++i)
        {
            res += mat[i][i] + mat[i][side_length - 1 - i];
        }
        if (side_length % 2)
        {
            res -= mat[side_length / 2][side_length / 2];
        }
        return res;
    }
};
// @lc code=end
