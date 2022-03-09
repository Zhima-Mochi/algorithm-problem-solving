/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int height = mat.size();
        int width = mat[0].size();
        vector<int> row_count = vector<int>(height);
        vector<int> col_count = vector<int>(width);
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (mat[i][j] == 1)
                {
                    ++row_count[i];
                    ++col_count[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i != height; ++i)
        {
            if (row_count[i] != 1)
            {
                continue;
            }
            for (int j = 0; j != width; ++j)
            {
                if (col_count[j] != 1)
                {
                    continue;
                }
                if (mat[i][j] == 1)
                {
                    ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end
