/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int width = image[0].size();
        for (auto &row_elem : image)
        {
            for (int i = 0; i * 2 < width; ++i)
            {
                if (row_elem[i] == row_elem[width - 1 - i])
                {
                    row_elem[i] = row_elem[width - 1 - i] ^= 1;
                }
            }
        }
        return image;
    }
};
// @lc code=end
