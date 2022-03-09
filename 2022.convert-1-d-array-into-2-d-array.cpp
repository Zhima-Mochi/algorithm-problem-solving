/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> res;
        if (m * n != original.size())
        {
            return res;
        }
        int c = 0;
        vector<int> elem;
        for (auto num : original)
        {
            elem.push_back(num);
            ++c;
            if (c == n)
            {
                res.push_back(elem);
                elem.clear();
                c = 0;
            }
        }
        return res;
    }
};
// @lc code=end
