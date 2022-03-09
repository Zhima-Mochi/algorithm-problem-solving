/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int w = graph.size();
        vector<int> link(w);
        for (int i = 0; i != w; ++i)
        {
            link[i] = 0;
            for (auto n : graph[i])
            {
                link[i] |= (1 << n);
            }
        }
        vector<vector<bool>> records(w, vector<bool>((1 << w)));
        vector<vector<int>> min_records(w, vector<int>((1 << w), -1));
        int min_res = INT_MAX;
        function<int(int, int)> dp = [&](int pos, int seen)
        {
            if (min_records[pos][seen] != -1)
            {
                return min_records[pos][seen];
            }

            if ((seen | (1 << pos)) == (1 << w) - 1)
            {
                return 0;
            }

            int res = INT_MAX;
            if (records[pos][seen])
            {
                return res;
            }
            records[pos][seen] = true;
            for (int i = 0; i != w; ++i)
            {
                if (link[pos] & (1 << i))
                {
                    res = min(res, dp(i, seen | (1 << pos)));
                }
            }
            records[pos][seen] = false;
            min_records[pos][seen] = res == INT_MAX ? INT_MAX : res + 1;
            return min_records[pos][seen];
        };
        for (int i = 0; i != w; ++i)
        {
            min_res = min(min_res, dp(i, 0));
        }
        return min_res;
    }
};
// @lc code=end
