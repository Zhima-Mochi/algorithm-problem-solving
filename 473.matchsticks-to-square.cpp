/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start
class Solution
{

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int total_length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total_length % 4)
        {
            return false;
        }
        int side_length = total_length / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> side_accum(4);
        if (matchsticks[0] > side_length)
        {
            return false;
        }
        return dfs(matchsticks, side_length, side_accum, 0);
    }
    bool dfs(vector<int> &matchsticks, const int &side_length, vector<int> &side_accum, int index)
    {
        if (index == matchsticks.size())
        {
            return true;
        }
        for (int i = 0; i != 4; ++i)
        {
            if (side_accum[i] + matchsticks[index] <= side_length)
            {
                bool seen = false;
                for (int j = 0; j != i; ++j)
                {
                    if (side_accum[i] == side_accum[j])
                    {
                        seen = true;
                        break;
                    }
                }
                if (seen)
                {
                    continue;
                }
                side_accum[i] += matchsticks[index];
                if (dfs(matchsticks, side_length, side_accum, index + 1))
                {
                    return true;
                }
                side_accum[i] -= matchsticks[index];
            }
        }
        return false;
    }
};
// @lc code=end
// class Solution
// {

// public:
//     bool makesquare(vector<int> &matchsticks)
//     {
//         int total_length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//         if (total_length % 4)
//         {
//             return false;
//         }
//         int side_length = total_length / 4;
//         map<int, int, greater<int>> umap;
//         for (auto &n : matchsticks)
//         {
//             ++umap[n];
//         }
//         return dfs(umap, side_length, 0, 0);
//     }
//     bool dfs(map<int, int, greater<int>> &umap, const int &side_length, int current_length, int count)
//     {
//         for (auto &p : umap)
//         {
//             if (p.second == 0)
//             {
//                 continue;
//             }
//             if (current_length + p.first == side_length)
//             {
//                 if (count == 3)
//                 {
//                     return true;
//                 }
//                 --p.second;
//                 if (dfs(umap, side_length, 0, count + 1))
//                 {
//                     return true;
//                 }
//                 ++p.second;
//             }
//             else if (current_length + p.first < side_length)
//             {
//                 --p.second;
//                 if (dfs(umap, side_length, current_length + p.first, count))
//                 {
//                     return true;
//                 }
//                 ++p.second;
//             }
//         }
//         return false;
//     }
// };