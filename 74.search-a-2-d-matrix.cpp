/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        int left = 0, right = height * width - 1;
        while (left < right)
        {
            auto middle = left + (right - left) / 2;
            auto &val = matrix[middle / width][middle % width];
            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return matrix[left / width][left % width] == target;
    }
};
// @lc code=end
