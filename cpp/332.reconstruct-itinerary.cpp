/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(n)
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> res;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> edges;
        for (auto &ticket : tickets)
        {
            edges[ticket[0]].push(ticket[1]);
        }
        string start = "JFK";
        function<void(string)> dfs = [&](string cur)
        {
            while (!edges[cur].empty())
            {
                string next_port = edges[cur].top();
                edges[cur].pop();
                dfs(next_port);
            }
            res.push_back(cur);
        };
        dfs(start);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
