/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, short> umap;
        for (auto &v : nums)
        {
            ++umap[v];
        }
        int res = 0;
        for (auto &pair : umap)
        {
            if (umap.count(pair.first + 1))
            {
                res = max(res, umap[pair.first + 1] + pair.second);
            }
        }
        return res;
    }
};
// @lc code=end
