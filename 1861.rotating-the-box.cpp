/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(w*h), s:O(w*h)
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int h = box.size();
        int w = box[0].size();
        vector<vector<int>> box_record(h, vector<int>(w));
        for (int i = 0; i != h; ++i)
        {
            int accum = 0;
            for (int j = 0; j != w; ++j)
            {
                if (box[i][j] == '#')
                {
                    accum++;
                    box[i][j] = '.';
                }
                else if (box[i][j] == '*')
                {
                    if (j > 0)
                    {
                        box_record[i][j - 1] = accum;
                    }
                    accum = 0;
                }
            }
            if (accum)
            {
                box_record[i].back() = accum;
            }
        }
        vector<vector<char>> res;
        for (int j = 0; j != w; ++j)
        {
            res.push_back(vector<char>());
            for (int i = h - 1; i != -1; --i)
            {
                res[j].push_back(box[i][j]);
            }
        }
        for (int j = w - 1; j != -1; --j)
        {
            for (int i = 0; i != h; ++i)
            {
                if (box_record[i][j])
                {
                    res[j][h - 1 - i] = '#';
                    if (box_record[i][j] > 1)
                    {
                        box_record[i][j - 1] = box_record[i][j] - 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
