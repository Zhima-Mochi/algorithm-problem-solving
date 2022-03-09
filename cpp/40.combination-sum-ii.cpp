/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int width = candidates.size();
        vector<int> pos_vec = {0};
        int sum = 0;
        vector<vector<int>> res;
        while (true)
        {
            if (pos_vec.back() != width)
            {
                if (sum + candidates[pos_vec.back()] == target)
                {
                    res.push_back({});
                    for (auto pos : pos_vec)
                    {
                        res.back().push_back(candidates[pos]);
                    }
                }
                else if (sum + candidates[pos_vec.back()] < target)
                {
                    sum += candidates[pos_vec.back()];
                    pos_vec.push_back(pos_vec.back() + 1);
                    continue;
                }
            }
            if (pos_vec.back() == width || sum + candidates[pos_vec.back()] >= target)
            {
                pos_vec.pop_back();
                if (pos_vec.empty())
                {
                    break;
                }
                sum -= candidates[pos_vec.back()];
                ++pos_vec.back();
                while (pos_vec.back() != width && candidates[pos_vec.back()] == candidates[pos_vec.back() - 1])
                {
                    pos_vec.back() += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
