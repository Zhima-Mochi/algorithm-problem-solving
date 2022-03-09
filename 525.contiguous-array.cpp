/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // key: sum_val value: index
        unordered_map<int, int> umap;
        umap[0] = -1;
        int res = 0;
        int sum_val = 0;
        int index = 0;
        for (auto n : nums)
        {
            if (n == 0)
            {
                --sum_val;
            }
            else
            {
                ++sum_val;
            }
            if (umap.count(sum_val))
            {
                res = max(res, index - umap[sum_val]);
            }
            else
            {
                umap[sum_val] = index;
            }
            ++index;
        }
        return res;
    }
};
// @lc code=end
