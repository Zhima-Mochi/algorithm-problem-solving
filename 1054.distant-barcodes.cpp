/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N+Klog(K)), s:O(N)
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> cnt;
        for (auto n : barcodes)
        {
            ++cnt[n];
        }
        vector<pair<int, int>> q(cnt.begin(), cnt.end());
        sort(q.begin(), q.end(), [&](pair<int, int> &l, pair<int, int> &r)
             { return l.second > r.second; });
        int w = barcodes.size();
        vector<int> res(w);
        int idx = 0;
        for (auto &p : q)
        {
            while (p.second)
            {
                res[idx] = p.first;
                --p.second;
                idx += 2;
                if (idx >= w)
                {
                    idx = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     vector<int> rearrangeBarcodes(vector<int> &barcodes)
//     {
//         int w = barcodes.size();
//         unordered_map<int, int> cnt;
//         auto comp = [&](int l, int r)
//         {
//             return cnt[l] < cnt[r];
//         };
//         priority_queue<int, vector<int>, decltype(comp)> q(comp);
//         for (auto n : barcodes)
//         {
//             ++cnt[n];
//         }
//         for (auto &p : cnt)
//         {
//             q.push(p.first);
//         }
//         vector<int> res;
//         res.reserve(w);
//         while (q.size())
//         {
//             vector<int> v;
//             v.push_back(q.top());
//             q.pop();
//             if (!res.empty() && v.back() == res.back())
//             {
//                 v.push_back(q.top());
//                 q.pop();
//             }
//             res.push_back(v.back());
//             if (--cnt[v.back()])
//             {
//                 q.push(v.back());
//             }
//             v.pop_back();
//             while (!v.empty())
//             {
//                 q.push(v.back());
//                 v.pop_back();
//             }
//         }
//         return res;
//     }
// };