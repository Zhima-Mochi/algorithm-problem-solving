/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto comp = [](pair<int, int> &l, pair<int, int> &r)
        { return l.first < r.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        int ind = 0;
        for (auto &&point : points)
        {
            pq.push({point[0] * point[0] + point[1] * point[1], ind});
            ++ind;
            if (pq.size() == k + 1)
            {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
