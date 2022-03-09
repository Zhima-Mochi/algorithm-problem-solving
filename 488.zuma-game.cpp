/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, int> seen_result;
    int color_count[5] = {};
    vector<char> color = {'R', 'Y', 'B', 'G', 'W'};

public:
    int findMinStep(string board, string hand)
    {
        for (char c : hand)
        {
            switch (c)
            {
            case 'R':
                color_count[0]++;
                break;
            case 'Y':
                color_count[1]++;
                break;
            case 'B':
                color_count[2]++;
                break;
            case 'G':
                color_count[3]++;
                break;
            case 'W':
                color_count[4]++;
                break;
            }
        }
        int res = helpler(board, color_count);
        return res == 6 ? -1 : res;
    }
    void erase_ball(string &board)
    {
        bool has_erased = true;
        while (has_erased)
        {
            has_erased = false;
            for (auto c : color)
            {
                int ind = board.find(string(3, c));
                if (ind != -1)
                {
                    int next_int = board.find_first_not_of(c, ind);
                    if (next_int == -1)
                    {
                        next_int = board.size();
                    }
                    board.erase(ind, next_int - ind);
                    has_erased = true;
                    break;
                }
            }
        }
    }
    int helpler(string board, int *color_count)
    {
        erase_ball(board);
        // string key = board + '|' + hand;
        if (board == "")
        {
            return 0;
        }
        else if (seen_result[board])
        {
            return seen_result[board];
        }
        int minimum = 6;
        for (int i = 0; i != 5; ++i)
        {
            if (color_count[i] == 0)
            {
                continue;
            }
            auto h = color[i];
            color_count[i]--;
            for (int j = 0, b_width = board.size(); j != b_width; ++j)
            {
                if (j > 0 && board[j] == board[j - 1] && board[j] != h)
                {
                    auto new_board = board.substr(0, j) + h + board.substr(j);
                    minimum = min(minimum, 1 + helpler(new_board, color_count));
                }
                else if (board[j] == h && (j + 1 == b_width || board[j + 1] != h))
                {
                    auto new_board = board.substr(0, j + 1) + h + board.substr(j + 1);
                    minimum = min(minimum, 1 + helpler(new_board, color_count));
                }
            }
            color_count[i]++;
        }
        seen_result[board] = minimum;
        return minimum;
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<string, int> seen_result;
//     vector<char> color = {'R', 'Y', 'B', 'G', 'W'};

// public:
//     int findMinStep(string board, string hand)
//     {
//         sort(hand.begin(), hand.end());
//         int res = helpler(board, hand);
//         return res == 6 ? -1 : res;
//     }
//     void erase_ball(string &board)
//     {
//         bool has_erased = true;
//         while (has_erased)
//         {
//             has_erased = false;
//             for (auto c : color)
//             {
//                 int ind = board.find(string(3, c));
//                 if (ind != -1)
//                 {
//                     int next_int = board.find_first_not_of(c, ind);
//                     if (next_int == -1)
//                     {
//                         next_int = board.size();
//                     }
//                     board.erase(ind, next_int - ind);
//                     has_erased = true;
//                     break;
//                 }
//             }
//         }
//     }
//     int helpler(string board, string hand)
//     {
//         erase_ball(board);
//         string key = board + '|' + hand;
//         if (board == "")
//         {
//             return 0;
//         }
//         else if (seen_result[key])
//         {
//             return seen_result[key];
//         }
//         int minimum = 6;
//         for (int i = 0, width = hand.size(); i != width; ++i)
//         {
//             if (i > 0 && hand[i] == hand[i - 1])
//             {
//                 continue;
//             }
//             auto h = hand[i];
//             string new_hand = hand.substr(0, i) + hand.substr(i + 1);
//             for (int j = 0, b_width = board.size(); j != b_width; ++j)
//             {
//                 if (board[j] != h)
//                 {
//                     auto new_board = board.substr(0, j) + h + board.substr(j);
//                     minimum = min(minimum, 1 + helpler(new_board, new_hand));
//                 }
//             }
//             minimum = min(minimum, 1 + helpler(board + h, new_hand));
//         }
//         seen_result[key] = minimum;
//         return minimum;
//     }
// };