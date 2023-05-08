/*
 * @lc app=leetcode id=1263 lang=cpp
 *
 * [1263] Minimum Moves to Move a Box to Their Target Location
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minPushBox(vector<vector<char>> &grid)
    {
        int box_row = 0, box_col = 0, person_row = 0, person_col = 0, target_row = 0, target_col = 0;
        int w = grid[0].size(), h = grid.size();
        for (int i = 0; i != h; ++i)
        {
            for (int j = 0; j != w; ++j)
            {
                if (grid[i][j] == 'B')
                {
                    box_row = i;
                    box_col = j;
                }
                else if (grid[i][j] == 'S')
                {
                    person_row = i;
                    person_col = j;
                }
                else if (grid[i][j] == 'T')
                {
                    target_row = i;
                    target_col = j;
                }
            }
        }
        unordered_map<int, int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        grid[box_row][box_col] = '#'; // avoid visiting again
        for (auto &d : directions)
        {
            int p_r = box_row + d[0], p_c = box_col + d[1];
            if (p_r < 0 || p_r >= h || p_c < 0 || p_c >= w || grid[p_r][p_c] == '#')
            {
                continue;
            }
            if (canReachPosition(grid, p_r, p_c, person_row, person_col))
            {
                q.push({0, generateKey(box_row, box_col, p_r, p_c)});
                visited[generateKey(box_row, box_col, p_r, p_c)] = 0;
            }
        }
        grid[box_row][box_col] = '.';
        while (!q.empty())
        {
            auto [step, key] = q.top();
            q.pop();
            vector<int> key_vec = parseKey(key);
            int r = key_vec[0], c = key_vec[1], p_r = key_vec[2], p_c = key_vec[3];

            int next_r = r + (r - p_r), next_c = c + (c - p_c);
            if (next_r < 0 || next_r >= h || next_c < 0 || next_c >= w || grid[next_r][next_c] == '#')
            {
                continue;
            }
            if (next_r == target_row && next_c == target_col)
            {
                return step + 1;
            }
            grid[next_r][next_c] = '#';
            for (auto &d : directions)
            {
                int next_p_r = next_r + d[0], next_p_c = next_c + d[1];
                if (next_p_r < 0 || next_p_r >= h || next_p_c < 0 || next_p_c >= w || grid[next_p_r][next_p_c] == '#')
                {
                    continue;
                }
                if (canReachPosition(grid, next_p_r, next_p_c, p_r, p_c))
                {
                    int next_key = generateKey(next_r, next_c, next_p_r, next_p_c);
                    if (visited.count(next_key) && visited[next_key] <= step + 1)
                    {
                        continue;
                    }
                    q.push({step + 1, next_key});
                    visited[next_key] = step + 1;
                }
            }
            grid[next_r][next_c] = '.';
        }
        return -1;
    }

    int generateKey(int row, int col, int p_row, int p_col)
    {
        return (row << 21) + (col << 14) + (p_row << 7) + p_col;
    }

    vector<int> parseKey(int key)
    {
        return {key >> 21, (key >> 14) & 0x7f, (key >> 7) & 0x7f, key & 0x7f};
    }

    bool canReachPosition(vector<vector<char>> &grid, int row, int col, int p_row, int p_col)
    {
        if (row == p_row && col == p_col)
        {
            return true;
        }
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        visited.insert((row << 7) + col);
        q.push({row, col});
        while (!q.empty())
        {
            int q_w = q.size();
            while (q_w--)
            {
                auto [r, c] = q.front();
                q.pop();
                for (auto &d : directions)
                {
                    int next_r = r + d[0], next_c = c + d[1];
                    if (next_r < 0 || next_r >= grid.size() || next_c < 0 || next_c >= grid[0].size() || grid[next_r][next_c] == '#')
                    {
                        continue;
                    }
                    if (next_r == p_row && next_c == p_col)
                    {
                        return true;
                    }
                    int key = (next_r << 7) + next_c;
                    if (visited.count(key))
                    {
                        continue;
                    }
                    visited.insert(key);
                    q.push({next_r, next_c});
                }
            }
        }
        return false;
    }
};
// @lc code=end
