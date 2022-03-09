/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int len = dominoes.size();
        if (len == 1)
        {
            return dominoes;
        }
        auto pos = dominoes.find_first_not_of('.');
        if (pos == -1)
        {
            return dominoes;
        }

        if (dominoes[pos] == 'L')
        {
            for (int i = 0; i != pos; ++i)
            {
                dominoes[i] = 'L';
            }
        }

        while (pos != len - 1)
        {
            auto next_pos = dominoes.find_first_not_of('.', pos + 1);
            if (next_pos == -1)
            {
                if (dominoes[pos] == 'R')
                {
                    for (int i = pos + 1; i != len; ++i)
                    {
                        dominoes[i] = 'R';
                    }
                }
                break;
            }
            if (dominoes[pos] == dominoes[next_pos])
            {
                auto &symbol = dominoes[pos];
                for (int i = pos + 1; i != next_pos; ++i)
                {
                    dominoes[i] = symbol;
                }
            }
            else if (dominoes[pos] == 'R')
            {
                auto middle_pt = pos + (next_pos - pos) / 2 + 1;
                for (int i = pos + 1; i != middle_pt; ++i)
                {
                    dominoes[i] = 'R';
                }
                for (int i = middle_pt; i != next_pos; ++i)
                {
                    dominoes[i] = 'L';
                }
                if ((next_pos - pos) % 2 == 0)
                {
                    dominoes[pos + (next_pos - pos) / 2] = '.';
                }
            }
            pos = next_pos;
        }
        return dominoes;
    }
};
// @lc code=end
