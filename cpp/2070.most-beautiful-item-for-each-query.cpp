/*
 * @lc app=leetcode id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
// t:O(mlog(m)+nlog(n)), s:O(m+log(n))
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());
        map<int, int> m;
        for (auto q : queries)
        {
            m[q] = 0;
        }
        auto cur = m.begin();
        int item_cur = 0;
        int w = items.size();
        while (cur != m.end() && item_cur != w)
        {
            if (items[item_cur][0] <= cur->first)
            {
                cur->second = max(cur->second, items[item_cur][1]);
                item_cur++;
            }
            else
            {
                cur = next(cur);
                cur->second = prev(cur)->second;
            }
        }
        while (cur != m.end())
        {
            cur = next(cur);
            cur->second = prev(cur)->second;
        }
        vector<int> res;
        for (auto q : queries)
        {
            res.push_back(m[q]);
        }
        return res;
    }
};
// @lc code=end
