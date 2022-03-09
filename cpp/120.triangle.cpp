/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> collection = {triangle[0][0]};
        int t_len = triangle.size();
        for (int i = 1; i != t_len; ++i)
        {
            int len = i;
            collection.push_back(collection.back() + triangle[i][len]);
            for (int j = len - 1; j > 0; --j)
            {
                collection[j] = min(collection[j], collection[j - 1]) + triangle[i][j];
            }
            collection[0] += triangle[i][0];
        }
        int res = collection[0];
        for (int i = 1; i != t_len; ++i)
        {
            res = min(collection[i], res);
        }
        return res;
    }
};
// @lc code=end
