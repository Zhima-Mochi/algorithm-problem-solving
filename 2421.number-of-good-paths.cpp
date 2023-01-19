/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        vector<vector<int>> relations;
        int w = vals.size();
        vector<int> order(w);
        vector<int> groups = order;
        function<int(int)> find = [&](int x) -> int
        { return groups[x] == x ? x : groups[x] = find(groups[x]); };
        for (int i = 0; i != w; ++i)
        {
            order[i] = i;
            groups[i] = i;
        }
        sort(order.begin(), order.end(), [&](int l, int r)
             { return vals[l] < vals[r]; });
        relations = vector<vector<int>>(w);
        for (auto &edge : edges)
        {
            relations[edge[0]].push_back(edge[1]);
            relations[edge[1]].push_back(edge[0]);
        }
        int res = w;
        vector<int> nums(w, 1);
        for (int i = 0; i != w; ++i)
        {
            int current = order[i];
            int current_val = vals[current];
            int current_group = find(current);
            for (int other : relations[current])
            {
                other = find(other);
                if (other == current_group || vals[other] > current_val)
                {
                    continue;
                }
                if (vals[other] == current_val)
                {
                    res += nums[current_group] * nums[other];
                    nums[current_group] += nums[other];
                }
                groups[other] = current_group;
            }
        }
        return res;
    }
};
// @lc code=end
