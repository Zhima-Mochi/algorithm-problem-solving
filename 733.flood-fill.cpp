/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
        {
            return image;
        }
        height = image.size();
        width = image[0].size();
        int oldColor=image[sr][sc];
        helpler(image, sr, sc, oldColor, newColor);
        return image;
    }
    void helpler(vector<vector<int>> &image, int sr, int sc, const int &oldColor, const int &newColor)
    {
        if (image[sr][sc] != oldColor)
        {
            return;
        }
        image[sr][sc] = newColor;
        if (sr > 0)
        {
            helpler(image, sr - 1, sc, oldColor, newColor);
        }
        if (sr < height - 1)
        {
            helpler(image, sr + 1, sc, oldColor, newColor);
        }
        if (sc > 0)
        {
            helpler(image, sr, sc - 1, oldColor, newColor);
        }
        if (sc < width - 1)
        {
            helpler(image, sr, sc + 1, oldColor, newColor);
        }
    }
};
// @lc code=end
