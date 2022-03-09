/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        int row_accum[3] = {0};
        int col_accum[3] = {0};
        int incline_accum[2] = {0};
        bool is_A = true;
        for (auto &round : moves)
        {
            if (is_A)
            {
                if (++row_accum[round[0]] == 3)
                {
                    return "A";
                }
                if (++col_accum[round[1]] == 3)
                {
                    return "A";
                }
                if (round[0] == round[1])
                {
                    if (++incline_accum[0] == 3)
                    {
                        return "A";
                    }
                }
                if (round[0] + round[1] == 2)
                {
                    if (++incline_accum[1] == 3)
                    {
                        return "A";
                    }
                }
            }
            else
            {
                if (--row_accum[round[0]] == -3)
                {
                    return "B";
                }
                if (--col_accum[round[1]] == -3)
                {
                    return "B";
                }
                if (round[0] == round[1])
                {
                    if (--incline_accum[0] == -3)
                    {
                        return "B";
                    }
                }
                if (round[0] + round[1] == 2)
                {
                    if (--incline_accum[1] == -3)
                    {
                        return "B";
                    }
                }
            }
            is_A = !is_A;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
// @lc code=end
