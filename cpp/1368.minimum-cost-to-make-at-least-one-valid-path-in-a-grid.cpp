/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
// t:O(mnlog(mn)), s:O(mn)
class Solution
{
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> memo(h, vector<int>(w, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            int cost = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            if (r == h - 1 && c == w - 1)
            {
                return cost;
            }
            pq.pop();
            for (int i = 1; i != 5; ++i)
            {
                vector<int> &dir = directions[i - 1];
                int next_r = r + dir[0];
                int next_c = c + dir[1];
                int next_cost = i == grid[r][c] ? cost : cost + 1;
                if (next_r >= h || next_r < 0 || next_c >= w || next_c < 0 || memo[next_r][next_c] <= next_cost)
                {
                    continue;
                }
                memo[next_r][next_c] = next_cost;
                pq.push({next_cost, next_r, next_c});
            }
        }
        return -1;
    }
};
// @lc code=end
