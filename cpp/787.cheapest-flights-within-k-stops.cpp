/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> cost_list = vector<int>(n, INT_MAX - 10000);
        cost_list[src] = 0;
        int res = INT_MAX - 10000;
        for (int i = 0; i < k + 1; ++i)
        {
            vector<int> next_cost_list = vector<int>(n, INT_MAX - 10000);
            for (auto &&flight : flights)
            {
                next_cost_list[flight[1]] = min(next_cost_list[flight[1]], cost_list[flight[0]] + flight[2]);
            }
            cost_list = move(next_cost_list);
            res = min(res, cost_list[dst]);
        }
        return res == INT_MAX - 10000 ? -1 : res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
//     {
//         vector<vector<int>> price_mat = vector<vector<int>>(n, vector<int>(n, -1));
//         vector<vector<int>> k_record = vector<vector<int>>(n, vector<int>(n, k + 1));
//         for (auto &&f : flights)
//         {
//             if (price_mat[f[0]][f[1]] == -1)
//             {
//                 price_mat[f[0]][f[1]] = f[2];
//             }
//             else
//             {
//                 price_mat[f[0]][f[1]] = min(price_mat[f[0]][f[1]], f[2]);
//             }
//         }
//         auto comp = [](vector<int> &l, vector<int> &r)
//         {
//             return l[0] > r[0];
//         };
//         priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
//         pq.push({0, src, 0});
//         while (!pq.empty())
//         {
//             auto record = pq.top();
//             pq.pop();
//             if (record[1] == dst)
//             {
//                 return record[0];
//             }
//             else if (record[2] == k + 1)
//             {
//                 continue;
//             }
//             for (auto i = 0; i != n; ++i)
//             {
//                 if (price_mat[record[1]][i] != -1 && k_record[record[1]][i] > record[2])
//                 {
//                     pq.push({record[0] + price_mat[record[1]][i], i, record[2] + 1});
//                     k_record[record[1]][i] = record[2];
//                 }
//             }
//         }
//         return -1;
//     }
// };