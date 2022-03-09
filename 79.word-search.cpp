/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    bool search(int i, int j, vector<vector<char>> &board, string &matched_word, size_t pos)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }
        if (board[i][j] != matched_word[pos])
        {
            return false;
        }
        if (pos == matched_word.size() - 1)
        {
            return true;
        }

        board[i][j] ^= -1;

        if (search(i - 1, j, board, matched_word, pos + 1) || search(i, j + 1, board, matched_word, pos + 1) || search(i + 1, j, board, matched_word, pos + 1) || search(i, j - 1, board, matched_word, pos + 1))
        {
            return true;
        }

        board[i][j] ^= -1;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        auto height = board.size();
        auto width = board[0].size();
        string &origin_word = word;
        string reverse_word;
        reverse_copy(word.begin(), word.end(), reverse_word.begin());
        auto unique_word = word;
        sort(unique_word.begin(), unique_word.end());
        unique(unique_word.begin(), unique_word.end());
        for (auto &c : unique_word)
        {
            bool has = false;
            for (auto &row : board)
            {
                for (auto &val : row)
                {
                    if (val == c)
                    {
                        has = true;
                        break;
                    }
                }
            }
            if (!has)
            {
                return false;
            }
        }
        //vector<vector<bool>> check_board(height, vector<bool>(width, false));
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (search(i, j, board, origin_word, 0) || search(i, j, board, reverse_word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
