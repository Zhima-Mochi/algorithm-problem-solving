/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        int res = 1;
        vector<vector<pair<int, int>>> umap(n);
        for (auto &edge : edges)
        {
            umap[edge[1]].push_back({edge[0], edge[2]});
            umap[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> restMoves(n, -1);
        restMoves[0] = maxMoves;
        auto comp = [&restMoves](const int &l, const int &r)
        {
            return make_pair(restMoves[l], l) > make_pair(restMoves[r], r);
        };
        set<int, decltype(comp)> q(comp);
        q.insert(0);
        while (!q.empty())
        {
            auto elem = *q.begin();
            q.erase(elem);
            for (auto &mp : umap[elem])
            {
                int currentRestMove = restMoves[elem] - mp.second;
                if (currentRestMove >= 1)
                {
                    if (restMoves[mp.first] == -1)
                    {
                        ++res;
                        restMoves[mp.first] = 0;
                    }
                    if (restMoves[mp.first] < currentRestMove - 1)
                    {
                        q.erase(mp.first); //it is necessary
                        restMoves[mp.first] = currentRestMove - 1;
                        q.insert(mp.first);
                    }
                }
            }
        }
        for (auto &num : restMoves)
        {
            if (num == -1)
            {
                num = 0;
            }
        }
        for (auto &edge : edges)
        {
            res += min(restMoves[edge[0]] + restMoves[edge[1]], edge[2]);
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
//     {
//         int res = 1;
//         unordered_map<int, unordered_map<int, int>> umap;
//         for (auto &edge : edges)
//         {
//             umap[edge[1]][edge[0]] = umap[edge[0]][edge[1]] = edge[2];
//         }
//         vector<int> restMoves(n, -1);
//         restMoves[0] = maxMoves;
//         queue<int> q;
//         q.push(0);
//         while (!q.empty())
//         {
//             int q_len = q.size();
//             while (q_len--)
//             {
//                 auto elem = q.front();
//                 q.pop();
//                 for (auto &mp : umap[elem])
//                 {
//                     int currentRestMove = restMoves[elem] - mp.second;
//                     if (currentRestMove >= 1)
//                     {
//                         if (restMoves[mp.first] == -1)
//                         {
//                             ++res;
//                             restMoves[mp.first] = 0;
//                         }
//                         if (restMoves[mp.first] < currentRestMove - 1)
//                         {
//                             restMoves[mp.first] = currentRestMove - 1;
//                             q.push(mp.first);
//                         }
//                     }
//                 }
//             }
//         }
//         for (auto &n : restMoves)
//         {
//             if (n == -1)
//             {
//                 n = 0;
//             }
//         }
//         for (auto &edge : edges)
//         {
//             res += min(restMoves[edge[0]] + restMoves[edge[1]], umap[edge[0]][edge[1]]);
//         }
//         return res;
//     }
// };