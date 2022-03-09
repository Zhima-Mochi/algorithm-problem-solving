/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// @lc code=start

// N=len(blocked)
// t:O(N*N), s:O(N*N)
class Solution
{
    vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    int block_size;
    bool match = false;

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        block_size = blocked.size();
        if (block_size < 2)
        {
            return true;
        }
        auto hash_fn = [fn = hash<long long>()](const pair<int, int> &o) -> size_t
        {
            auto &[x, y] = o;
            return fn((long long)x << 32 | y);
        };
        unordered_set<pair<int, int>, decltype(hash_fn)> blocked_pos(0, hash_fn);
        for (auto &b : blocked)
        {
            blocked_pos.emplace(b[0], b[1]);
        }
        auto breakthrough_block = [&](vector<int> &start_pos, vector<int> &end_pos)
        {
            int start_x = start_pos[0];
            int start_y = start_pos[1];
            int end_x = end_pos[0];
            int end_y = end_pos[1];
            queue<pair<int, int>> around_pos_val;
            around_pos_val.emplace(start_x, start_y);
            unordered_set<pair<int, int>, decltype(hash_fn)> seen(0, hash_fn);
            seen.emplace(start_x, start_y);
            int max_blank_num = block_size * (block_size - 1) / 2;
            while (!around_pos_val.empty() && max_blank_num > 0)
            {
                auto [x, y] = around_pos_val.front();
                around_pos_val.pop();
                for (int i = 0; i != 4; ++i)
                {
                    int next_x = x + directions[i][0];
                    int next_y = y + directions[i][1];
                    if (next_x < 0 || next_x >= 1000000)
                    {
                        continue;
                    }
                    if (next_y < 0 || next_y >= 1000000)
                    {
                        continue;
                    }
                    if (next_x == end_x && next_y == end_y)
                    {
                        match = true;
                        return true;
                    }
                    else if (!blocked_pos.count({next_x, next_y}) && !seen.count({next_x, next_y}))
                    {
                        seen.emplace(next_x, next_y);
                        around_pos_val.emplace(next_x, next_y);
                        --max_blank_num;
                    }
                }
            }
            return max_blank_num <= 0;
        };

        if (!breakthrough_block(source, target))
        {
            return false;
        }
        else if (match)
        {
            return true;
        }
        if (!breakthrough_block(target, source))
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

// N=len(blocked)
// t:O(N*N), s:O(N*N)
// class Solution
// {
//     vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
//     unordered_set<long long> blocked_pos_val;
//     int block_size;
//     long long source_val;
//     long long target_val;
//     bool match = false;

// public:
//     bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
//     {
//         source_val = pos_transfer(source);
//         target_val = pos_transfer(target);
//         block_size = blocked.size();
//         for (auto &b : blocked)
//         {
//             blocked_pos_val.insert(pos_transfer(b));
//         }
//         if (!breakthrough_block(source_val, target_val))
//         {
//             return false;
//         }
//         else if (match)
//         {
//             return true;
//         }
//         if (!breakthrough_block(target_val, source_val))
//         {
//             return false;
//         }
//         return true;
//     }
//     long long pos_transfer(vector<int> pos)
//     {
//         return (static_cast<long long>(pos[0]) << 32) + pos[1];
//     }
//     bool breakthrough_block(long long start_val, long long counterpart_val)
//     {
//         int start_x = start_val >> 32;
//         int start_y = start_val & (~0LL >> 32);
//         queue<long long> around_pos_val;
//         around_pos_val.push(start_val);
//         unordered_set<long long> seen;
//         int max_blank_num = block_size * (block_size - 1) / 2;
//         while (!around_pos_val.empty() && max_blank_num >= 0)
//         {
//             int x = around_pos_val.front() >> 32;
//             int y = around_pos_val.front() & (~0LL >> 32);
//             around_pos_val.pop();
//             for (int i = 0; i != 4; ++i)
//             {
//                 if (x + directions[i][0] < 0 || x + directions[i][0] >= 1000000)
//                 {
//                     continue;
//                 }
//                 if (y + directions[i][1] < 0 || y + directions[i][1] >= 1000000)
//                 {
//                     continue;
//                 }
//                 long long val = pos_transfer({x + directions[i][0], y + directions[i][1]});
//                 if (!blocked_pos_val.count(val) && !seen.count(val))
//                 {
//                     if (val == counterpart_val)
//                     {
//                         match = true;
//                         return true;
//                     }
//                     else
//                     {
//                         --max_blank_num;
//                     }
//                     seen.insert(val);
//                     around_pos_val.push(val);
//                 }
//             }
//         }
//         return max_blank_num < 0;
//     }
// };