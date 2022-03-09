/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if (mat == target)
        {
            return true;
        }
        int width = mat.size();
        bool is_fine = true;
        for (int i = 0; i != width; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (mat[i][j] != target[j][width - 1 - i])
                {
                    is_fine = false;
                    break;
                }
            }
            if (!is_fine)
            {
                break;
            }
        }
        if (is_fine)
        {
            return true;
        }
        is_fine = true;
        for (int i = 0; i != width; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (mat[i][j] != target[width - 1 - i][width - 1 - j])
                {
                    is_fine = false;
                    break;
                }
            }
            if (!is_fine)
            {
                break;
            }
        }
        if (is_fine)
        {
            return true;
        }

        is_fine = true;
        for (int i = 0; i != width; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (mat[i][j] != target[width - 1 - j][i])
                {
                    is_fine = false;
                    break;
                }
            }
            if (!is_fine)
            {
                break;
            }
        }
        return is_fine;
    }
};
// @lc code=end
