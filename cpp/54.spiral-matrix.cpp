/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            up++;
            if (up > down)
            {
                break;
            }
            for (int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (left > right)
            {
                break;
            }
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            if (up > down)
            {
                break;
            }
            for (int i = down; i >= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            if (left > right)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
