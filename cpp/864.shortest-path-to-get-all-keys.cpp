/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(m*n*2^k), s:O(m*n*2^k)
class Solution
{
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        unordered_map<char, int> key_to_num;
        int h = grid.size(), w = grid[0].size();
        int key_cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (islower(grid[i][j]))
                {
                    if (!key_to_num.count(grid[i][j]))
                    {
                        key_to_num[grid[i][j]] = key_cnt++;
                    }
                }
                else if (grid[i][j] == '@')
                {
                    q.push({0, pos_to_val(i, j)});
                }
            }
        }
        vector<vector<bool>> seen(1 << 10, vector<bool>(1 << key_to_num.size()));
        seen[q.front().second][0] = true;
        int res = 0;
        while (!q.empty())
        {
            int q_w = q.size();
            res++;
            while (q_w--)
            {
                auto [current_key, val] = q.front();
                q.pop();
                auto pos = val_to_pos(val);
                for (auto &dir : directions)
                {
                    int next_r = pos.first + dir[0];
                    int next_c = pos.second + dir[1];
                    if (next_r < 0 || next_r == h || next_c < 0 || next_c == w || grid[next_r][next_c] == '#')
                    {
                        continue;
                    }
                    int next_key = current_key;
                    if (islower(grid[next_r][next_c]))
                    {
                        next_key = current_key | (1 << key_to_num[grid[next_r][next_c]]);
                        if (next_key == (1 << key_cnt) - 1)
                        {
                            return res;
                        }
                        else if (!seen[pos_to_val(next_r, next_c)][next_key])
                        {
                            seen[pos_to_val(next_r, next_c)][next_key] = true;
                            q.push({next_key, pos_to_val(next_r, next_c)});
                        }
                    }
                    else if (isupper(grid[next_r][next_c]))
                    {
                        if (current_key & (1 << key_to_num[tolower(grid[next_r][next_c])]))
                        {
                            if (!seen[pos_to_val(next_r, next_c)][next_key])
                            {
                                seen[pos_to_val(next_r, next_c)][next_key] = true;
                                q.push({next_key, pos_to_val(next_r, next_c)});
                            }
                        }
                    }
                    else
                    {
                        if (!seen[pos_to_val(next_r, next_c)][next_key])
                        {
                            seen[pos_to_val(next_r, next_c)][next_key] = true;
                            q.push({next_key, pos_to_val(next_r, next_c)});
                        }
                    }
                }
            }
        }
        return -1;
    }
    int pos_to_val(int row, int col)
    {
        return (row << 5) + col;
    }
    pair<int, int> val_to_pos(int val)
    {
        return {val >> 5, val & 31};
    }
};
// @lc code=end
