/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<int> res = {grid[0][0]};

        auto width = grid[0].size();
        for (int i = 1; i != width; i++)
        {
            res.push_back(res.back() + grid[0][i]);
        }
        auto height = grid.size();
        for (int i = 1; i != height; i++)
        {
            res[0] += grid[i][0];
            for (int j = 1; j != width; j++)
            {
                res[j] = min(res[j - 1], res[j]) + grid[i][j];
            }
        }
        return res[width - 1];
        // using elem = string;
        // unordered_map<string, int> path;
        // char shift = -100;
        // char height = grid.size() - 1 + shift, width = grid[0].size() - 1 + shift;
        // path[elem{height, width}] = grid[height - shift][width - shift];
        // while (path.find(elem{shift, shift}) == path.end())
        // {

        //     unordered_map<elem, int> new_path;
        //     for (auto &p : path)
        //     {
        //         char h_pos = p.first[0], w_pos = p.first[1];
        //         auto sum = p.second;
        //         if (h_pos > shift)
        //         {
        //             if (new_path.find(elem{static_cast<char>(h_pos - 1), w_pos}) != new_path.end())
        //             {
        //                 new_path[elem{static_cast<char>(h_pos - 1), w_pos}] = min(new_path[elem{static_cast<char>(h_pos - 1), w_pos}], sum + grid[h_pos - 1 - shift][w_pos - shift]);
        //             }
        //             else
        //             {
        //                 new_path[elem{static_cast<char>(h_pos - 1), w_pos}] = sum + grid[h_pos - 1 - shift][w_pos - shift];
        //             }
        //         }
        //         if (w_pos > shift)
        //         {
        //             if (new_path.find(elem{h_pos, static_cast<char>(w_pos - 1)}) != new_path.end())
        //             {
        //                 new_path[elem{h_pos, static_cast<char>(w_pos - 1)}] = min(new_path[elem{h_pos, static_cast<char>(w_pos - 1)}], sum + grid[h_pos - shift][w_pos - 1 - shift]);
        //             }
        //             else
        //             {
        //                 new_path[elem{h_pos, static_cast<char>(w_pos - 1)}] = sum + grid[h_pos - shift][w_pos - 1 - shift];
        //             }
        //         }
        //     }
        //     path = new_path;
        // }
        // return path.begin()->second;
    }
};
// @lc code=end
