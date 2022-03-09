/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (auto &n : nums)
        {
            ++umap[n];
        }
        vector<pair<int, int>> vec;
        for (auto &pair : umap)
        {
            vec.push_back({pair.first, pair.second});
        }
        make_heap(vec.begin(), vec.end(), [](pair<int, int> &l, pair<int, int> &r)
                  { return l.second < r.second; });
        vector<int> res;
        while (k--)
        {
            pop_heap(vec.begin(), vec.end(), [](pair<int, int> &l, pair<int, int> &r)
                     { return l.second < r.second; });
            res.push_back(vec.back().first);
            vec.pop_back();
        }
        return res;
    }
};
// @lc code=end
