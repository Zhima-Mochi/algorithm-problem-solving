/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(mn), s:O(mn)
class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> res;
        int h = land.size(), w = land[0].size();
        land.push_back(vector<int>(w));
        for (int i = 0; i != h + 1; ++i)
        {
            vector<int> v;
            for (int j = 0; j != w; ++j)
            {
                if (i > 0 && land[i][j] == 0 && land[i - 1][j] != 0)
                {
                    if (v.size() == 0)
                    {
                        v.push_back(i - land[i - 1][j]);
                        v.push_back(j);
                        v.push_back(i - 1);
                        v.push_back(j);
                    }
                    else
                    {
                        v.back() = j;
                    }
                }
                else
                {
                    if (!v.empty())
                    {
                        res.push_back(v);
                        v.clear();
                    }
                }
                if (land[i][j] == 1)
                {
                    if (i > 0)
                    {
                        land[i][j] += land[i - 1][j];
                    }
                }
            }
            if (!v.empty())
            {
                res.push_back(v);
                v.clear();
            }
        }
        return res;
    }
};
// @lc code=end
