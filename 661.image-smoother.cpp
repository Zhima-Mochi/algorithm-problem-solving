/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        height = img.size();
        width = img[0].size();
        if (height == 1 && width == 1)
        {
            return img;
        }
        else if (height == 1)
        {
            auto res = vector<vector<int>>(height, vector<int>(width));
            res[0][0] = (img[0][0] + img[0][1]) / 2;
            res[0][width - 1] = (img[0][width - 1] + img[0][width - 2]) / 2;

            for (int j = 1; j != width - 1; ++j)
            {
                res[0][j] = (img[0][j - 1] + img[0][j] + img[0][j + 1]) / 3;
            }
            return res;
        }
        else if (width == 1)
        {
            auto res = vector<vector<int>>(height, vector<int>(width));
            res[0][0] = (img[0][0] + img[1][0]) / 2;
            res[height - 1][0] = (img[height - 1][0] + img[height - 2][0]) / 2;

            for (int i = 1; i != height - 1; ++i)
            {
                res[i][0] = (img[i - 1][0] + img[i][0] + img[i + 1][0]) / 3;
            }
            return res;
        }
        auto res = vector<vector<int>>(height, vector<int>(width));

        for (int i = 0; i != height; ++i)
        {
            res[i][0] = img[i][0] + img[i][1];
            res[i][width - 1] = img[i][width - 1] + img[i][width - 2];
            for (int j = 1; j != width - 1; ++j)
            {
                res[i][j] = img[i][j - 1] + img[i][j] + img[i][j + 1];
            }
        }
        img[0][0] = (res[0][0] + res[1][0]) / 4;
        img[height - 1][0] = (res[height - 1][0] + res[height - 2][0]) / 4;
        img[0][width - 1] = (res[0][width - 1] + res[1][width - 1]) / 4;
        img[height - 1][width - 1] = (res[height - 1][width - 1] + res[height - 2][width - 1]) / 4;

        for (int j = 1; j != width - 1; ++j)
        {
            img[0][j] = (res[0][j] + res[1][j]) / 6;
            img[height - 1][j] = (res[height - 1][j] + res[height - 2][j]) / 6;
        }
        for (int i = 1; i != height - 1; ++i)
        {
            img[i][0] = (res[i - 1][0] + res[i][0] + res[i + 1][0]) / 6;
            img[i][width - 1] = (res[i - 1][width - 1] + res[i][width - 1] + res[i + 1][width - 1]) / 6;
            for (int j = 1; j != width - 1; ++j)
            {
                img[i][j] = (res[i - 1][j] + res[i][j] + res[i + 1][j]) / 9;
            }
        }

        return img;
    }
};
// @lc code=end
