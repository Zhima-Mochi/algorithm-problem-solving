/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        vector<vector<int>> graph(n + 1);
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        vector<double> probs(n + 1, 0);
        function<void(int, int, double)> dp = [&](int t, int pos, double current_prob) -> void
        {
            if (t == 0)
            {
                probs[pos] += current_prob;
                return;
            }
            vector<int> next_poss;
            for (auto next_pos : graph[pos])
            {
                if (!visited[next_pos])
                {
                    next_poss.push_back(next_pos);
                }
            }
            if (next_poss.empty())
            {
                probs[pos] += current_prob;
                return;
            }
            double next_prob = current_prob / next_poss.size();
            for (auto p : next_poss)
            {
                visited[p] = true;
                dp(t - 1, p, next_prob);
                visited[p] = false;
            }
        };
        dp(t, 1, 1);
        return probs[target];
    }
};
// @lc code=end