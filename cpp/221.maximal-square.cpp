/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        height = matrix.size();
        width = matrix[0].size();
        vector<int> vec(width);
        int res = 0;
        for (int i = 0; i != width; ++i)
        {
            if (matrix[0][i] == '1')
            {
                vec[i] = 1;
                res = 1;
            }
        }
        for (int i = 1; i != height; ++i)
        {
            auto next_vec = vec;
            if (matrix[i][0] == '1')
            {
                next_vec[0] = 1;
                res = max(res, 1);
            }
            else
            {
                next_vec[0] = 0;
            }
            for (int j = 1; j != width; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    next_vec[j] = 1 + min(min(next_vec[j - 1], vec[j]), vec[j - 1]);
                    res = max(res, next_vec[j]);
                }
                else
                {
                    next_vec[j] = 0;
                }
            }
            swap(next_vec, vec);
        }
        return res * res;
    }
};
// @lc code=end

