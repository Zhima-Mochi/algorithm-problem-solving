/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
// N = size of board
// t:O(N), s:O(N)
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int w = board.size();
        int goal = w * w;
        int turn = 0;
        queue<int> q;
        unordered_set<int> seen;
        q.push(1);
        while (!q.empty())
        {
            ++turn;
            int q_w = q.size();
            while (q_w--)
            {
                int pos = q.front();
                q.pop();
                if (pos + 6 >= goal)
                {
                    return turn;
                }
                int last_no_fast_move_pos = -1;
                for (int move_to = pos + 1; move_to <= pos + 6; ++move_to)
                {
                    int next_pos = board[w - (move_to - 1) / w - 1][(move_to - 1) / w % 2 == 0 ? (move_to - 1) % w : w - (move_to - 1) % w - 1];
                    if (next_pos == goal)
                    {
                        return turn;
                    }
                    if (next_pos != -1)
                    {
                        if (!seen.count(next_pos))
                        {
                            seen.insert(next_pos);
                            q.push(next_pos);
                        }
                    }
                    else
                    {
                        last_no_fast_move_pos = move_to;
                    }
                }
                if (last_no_fast_move_pos != -1 && !seen.count(last_no_fast_move_pos))
                {
                    seen.insert(last_no_fast_move_pos);
                    q.push(last_no_fast_move_pos);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
