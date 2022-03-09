/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int height = mat.size(), width = mat[0].size();
        if (height * width != r * c)
        {
            return mat;
        }
        vector<vector<int>> res;
        auto count = 0;
        for (auto &row : mat)
        {
            for (auto &val : row)
            {
                count++;
                if (count % c == 1 || c == 1)
                {
                    res.push_back(vector<int>());
                }
                res.back().push_back(val);
            }
        }
        return res;
    }
};
// @lc code=end
