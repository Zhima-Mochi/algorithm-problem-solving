/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
// @lc code=start

// t: O(n+m) s: O(n+m)
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int width = quiet.size();
        vector<vector<int>> richer_than(width);
        vector<int> richer_than_self_num(width);
        for (auto &&rich : richer)
        {
            richer_than[rich[0]].push_back(rich[1]);
            ++richer_than_self_num[rich[1]];
        }

        vector<int> res(width);
        iota(res.begin(), res.end(), 0);
        queue<int> q;
        for (int i = 0; i != width; ++i)
        {
            if (richer_than_self_num[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int ind = q.front();
            q.pop();
            for (int sub_ind : richer_than[ind])
            {
                if (quiet[res[ind]] < quiet[res[sub_ind]])
                {
                    res[sub_ind] = res[ind];
                }
                if (--richer_than_self_num[sub_ind] == 0)
                {
                    q.push(sub_ind);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// t: O(log(n)+m) s: O(n+m)
// class Solution
// {
// public:
//     vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
//     {
//         int width = quiet.size();
//         vector<bool> seen(width);
//         vector<vector<int>> richer_than(width);
//         for (auto &&rich : richer)
//         {
//             richer_than[rich[0]].push_back(rich[1]);
//         }
//         vector<int> quiet_index(width);
//         for (int i = 1; i != width; ++i)
//         {
//             quiet_index[i] = i;
//         }
//         sort(quiet_index.begin(), quiet_index.end(), [&quiet](auto const &l, auto const &r)
//              { return quiet[l] < quiet[r]; });
             
//         vector<int> res(width);
//         for (auto &&richer_ind : quiet_index)
//         {
//             if (seen[richer_ind])
//             {
//                 continue;
//             }
//             else
//             {
//                 queue<int> replaced_ind;
//                 replaced_ind.push(richer_ind);
//                 while (!replaced_ind.empty())
//                 {
//                     auto cur_ind = replaced_ind.front();
//                     replaced_ind.pop();
//                     if (seen[cur_ind])
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         seen[cur_ind] = true;
//                         res[cur_ind] = richer_ind;
//                         for (auto &&n : richer_than[cur_ind])
//                         {
//                             if (!seen[n])
//                             {
//                                 replaced_ind.push(n);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };