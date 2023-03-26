/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
// t: O(n), s: O(n)
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int res = -1;
        int w = edges.size();
        int prev_step = 1;
        for (int i = 0; i != w; ++i)
        {
            if (edges[i] < -1)
            {
                continue;
            }
            int step = prev_step + 1;
            int pos = i;
            while (pos != -1 && edges[pos] > -1)
            {
                int next_pos = edges[pos];
                edges[pos] = -step;
                step += 1;
                pos = next_pos;
            }
            if (pos != -1 && -edges[pos] > prev_step)
            {
                res = max(res, step + edges[pos]);
            }
            prev_step = step;
        }
        return res;
    }
};
// @lc code=end
