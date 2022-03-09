/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int height = dungeon.size(), width = dungeon[0].size();
        vector<int> dp(width + 1, INT_MAX);
        dp[width - 1] = 1;
        //backward induction
        for (int i = height - 1; i != -1; --i)
        {
            for (int j = width - 1; j != -1; --j)
            {
                //decide the minimum health power if knight "start at here"
                dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j];
                dp[j] = max(dp[j], 1);
            }
        }
        return dp[0];
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int calculateMinimumHP(vector<vector<int>> &dungeon)
//     {
//         int height = dungeon.size(), width = dungeon[0].size();
//         vector<vector<pair<int, int>>> dp(width);
//         dp[0].push_back({min(dungeon[0][0], 0), dungeon[0][0]});
//         for (int j = 1; j != width; ++j)
//         {
//             dp[j] = pick_route(dp[j - 1], vector<pair<int, int>>(), dungeon[0][j]);
//         }
//         for (int i = 1; i != height; ++i)
//         {
//             dp[0] = pick_route(vector<pair<int, int>>(), dp[0], dungeon[i][0]);
//             for (int j = 1; j != width; ++j)
//             {
//                 dp[j] = move(pick_route(dp[j - 1], dp[j], dungeon[i][j]));
//             }
//         }
//         return -dp[width - 1].front().first + 1;
//     }
//     void insert_stategy(vector<pair<int, int>> &res, pair<int, int> elem, int val)
//     {
//         elem.second += val;
//         elem.first = min(elem.first, elem.second);
//         while (!res.empty() && res.back().first < elem.first)
//         {
//             res.pop_back();
//         }
//         if (res.empty())
//         {
//             res.push_back(elem);
//         }
//         else if (res.back().second < elem.second)
//         {
//             if (res.back().first == elem.first)
//             {
//                 res.pop_back();
//             }
//             res.push_back(elem);
//         }
//     }
//     vector<pair<int, int>> pick_route(const vector<pair<int, int>> &left, const vector<pair<int, int>> &up, int val)
//     {
//         int cur_left = 0, cur_up = 0;
//         int width_left = left.size(), width_up = up.size();
//         vector<pair<int, int>> res;
//         while (cur_left != width_left && cur_up != width_up)
//         {
//             if (left[cur_left].first > up[cur_up].first)
//             {
//                 insert_stategy(res, left[cur_left], val);
//                 ++cur_left;
//             }
//             else if (left[cur_left].first < up[cur_up].first)
//             {
//                 insert_stategy(res, up[cur_up], val);
//                 ++cur_up;
//             }
//             else
//             {
//                 if (left[cur_left].second >= up[cur_up].second)
//                 {
//                     insert_stategy(res, left[cur_left], val);
//                     ++cur_left;
//                 }
//                 else
//                 {
//                     insert_stategy(res, up[cur_up], val);
//                     ++cur_up;
//                 }
//             }
//         }
//         while (cur_left != width_left)
//         {
//             insert_stategy(res, left[cur_left], val);
//             ++cur_left;
//         }
//         while (cur_up != width_up)
//         {
//             insert_stategy(res, up[cur_up], val);
//             ++cur_up;
//         }
//         return res;
//     }
// };