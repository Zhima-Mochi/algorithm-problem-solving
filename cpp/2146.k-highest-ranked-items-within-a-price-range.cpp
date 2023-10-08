/*
 * @lc app=leetcode id=2146 lang=cpp
 *
 * [2146] K Highest Ranked Items Within a Price Range
 */
#include <vector>
#include <queue>
#include <functional>
using namespace std;
// @lc code=start
// t:O(m*n*log(k)), s:O(m*n)
class Solution
{
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        // dist, price, row, col
        auto comp = [&](tuple<int, int, int, int> &a, tuple<int, int, int, int> &b)
        {
            return a < b;
        };
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, decltype(comp)> pq(comp);

        queue<tuple<int, int>> q;
        q.push(make_tuple(start[0], start[1]));
        int dist = 0;
        while (!q.empty())
        {
            int q_len = q.size();
            while (q_len--)
            {
                auto curr = q.front();
                q.pop();
                int r = get<0>(curr);
                int c = get<1>(curr);
                int price = grid[r][c];
                grid[r][c] = 0;
                if (price == 0)
                {
                    continue;
                }
                if (price <= pricing[1] && price >= pricing[0])
                {
                    pq.push(make_tuple(dist, price, r, c));
                    if (pq.size() > k)
                    {
                        pq.pop();
                    }
                }
                for (auto dir : directions)
                {
                    int new_r = r + dir.first;
                    int new_c = c + dir.second;
                    if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] != 0)
                    {
                        q.push(make_tuple(new_r, new_c));
                    }
                }
            }
            dist++;
            if (pq.size() == k && dist > get<0>(pq.top()))
            {
                break;
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            auto curr = pq.top();
            res.push_back({get<2>(curr), get<3>(curr)});
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
