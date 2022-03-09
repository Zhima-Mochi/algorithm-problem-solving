/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int height = matrix.size(), width = matrix[0].size();
        if (matrix[0][0] > target || matrix[height - 1][width - 1] < target)
        {
            return false;
        }
        int up = 0, down = height - 1;
        while (up < down)
        {
            int mid = up + (down - up) / 2;
            if (matrix[mid][width - 1] < target)
            {
                up = mid + 1;
            }
            else
            {
                down = mid;
            }
        }
        int left = 0, right = width - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[height - 1][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        right = width - 1;
        while (up != height && right >= left)
        {
            if (matrix[up][right] > target)
            {
                --right;
            }
            else if (matrix[up][right] < target)
            {
                ++up;
            }
            else
            {
                return true;
            }
        }
        // right = width - 1;
        // for (int i = up; i != height; ++i)
        // {
        //     if (matrix[i][right] > target)
        //     {
        //         int sub_left = left;
        //         while (sub_left < right)
        //         {
        //             auto mid = sub_left + (right - sub_left + 1) / 2;
        //             if (matrix[i][mid] > target)
        //             {
        //                 right = mid - 1;
        //             }
        //             else
        //             {
        //                 sub_left = mid;
        //             }
        //         }
        //     }
        //     if (matrix[i][right] == target)
        //     {
        //         return true;
        //     }
        //     if (right == left)
        //     {
        //         int down = height - 1;
        //         while (i < down)
        //         {
        //             int mid = i + (down - i) / 2;
        //             if (matrix[mid][left] < target)
        //             {
        //                 i = mid + 1;
        //             }
        //             else
        //             {
        //                 down = mid;
        //             }
        //         }
        //         return matrix[i][left] == target;
        //     }
        // }

        return false;
    }
};
// @lc code=end
