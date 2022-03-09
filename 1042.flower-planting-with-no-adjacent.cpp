/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
    unordered_map<int, vector<int>> route_map;
    vector<int> color_record;
    int N;

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        for (auto &path : paths)
        {
            route_map[path[0]].push_back(path[1]);
            route_map[path[1]].push_back(path[0]);
        }
        color_record = vector<int>(n);
        N = n;
        dfs(1);
        return color_record;
    }
    void dfs(int idx)
    {
        if (idx == N + 1)
        {
            return;
        }
        int bit = 0;
        for (auto garden : route_map[idx])
        {
            if (garden < idx)
            {
                bit |= 1 << color_record[garden - 1] - 1;
            }
        }
        for (int i = 1; i != 5; ++i)
        {
            if ((bit & 1) == 0)
            {
                color_record[idx - 1] = i;
                dfs(idx + 1);
                return;
            }
            bit >>= 1;
        }
        return;
    }
};
// @lc code=end
