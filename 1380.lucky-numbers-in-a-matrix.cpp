/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<int> row(height, 100001), col(width, 0), res;
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (row[i] == col[j])
                {
                    res.push_back(row[i]);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
