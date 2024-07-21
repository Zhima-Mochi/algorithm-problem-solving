/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */
#include <vector>
#include <unordered_set>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>> &adj) {
        vector<int> indegree(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            for (int next : adj[i]) {
                indegree[next]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (order.size() == k) {
            return order;
        } else {
            return {};
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        vector<vector<int>> row_next(k + 1), col_next(k + 1);

        for (auto &c : rowConditions) {
            row_next[c[0]].push_back(c[1]);
        }

        for (auto &c : colConditions) {
            col_next[c[0]].push_back(c[1]);
        }

        vector<int> row_order = topologicalSort(k, row_next);
        vector<int> col_order = topologicalSort(k, col_next);

        if (row_order.empty() || col_order.empty()) {
            return vector<vector<int>>{};
        }

        vector<int> row_pos(k + 1), col_pos(k + 1);
        for (int i = 0; i < k; i++) {
            row_pos[row_order[i]] = i;
            col_pos[col_order[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            ans[row_pos[i]][col_pos[i]] = i;
        }

        return ans;
    }
};

// @lc code=end
