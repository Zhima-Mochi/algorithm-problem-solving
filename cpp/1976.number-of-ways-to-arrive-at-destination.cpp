/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n^2)
int MOD = 1000000007;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int bound = 1000000001;
        vector<vector<int>> graphs(n, vector<int>(n, bound));
        for (auto &road : roads)
        {
            graphs[road[0]][road[1]] = min(graphs[road[0]][road[1]], road[2]);
            graphs[road[1]][road[0]] = min(graphs[road[1]][road[0]], road[2]);
        }
        vector<long long> dist(n, -1);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        vector<bool> seen(n);
        vector<long long> ways(n);
        ways[0] = 1;
        while (!q.empty())
        {
            auto [t, i] = q.top();
            q.pop();
            seen[i] = true;
            for (int j = 0; j != n; ++j)
            {
                if (seen[j] || graphs[i][j] == bound)
                {
                    continue;
                }
                if (dist[j] == -1 || dist[j] > t + graphs[i][j])
                {
                    dist[j] = t + graphs[i][j];
                    ways[j] = ways[i];
                    q.push({dist[j], j});
                }
                else if (dist[j] == t + graphs[i][j])
                {
                    ways[j] = (ways[j] + ways[i]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
// @lc code=end
