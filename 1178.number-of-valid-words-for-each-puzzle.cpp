/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start

// reverse thinking
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> word_bit_count;
        for (auto &word : words)
        {
            ++word_bit_count[make_bit(word)];
        }
        int width = puzzles.size();
        vector<int> res(width);
        for (auto i = 0; i != width; ++i)
        {
            for (int j = 0; j != 64; ++j)
            {
                string new_puzzle = puzzles[i];
                for (int k = 1; k != 7; ++k)
                {
                    if ((1 << k) & (j << 1))
                    {
                        new_puzzle[k] = new_puzzle[0];
                    }
                }
                int puzzle_bit = make_bit(new_puzzle);
                if (word_bit_count.count(puzzle_bit))
                {
                    res[i] += word_bit_count[puzzle_bit];
                }
            }
        }
        return res;
    }
    int make_bit(string &word)
    {
        int res = 0;
        for (auto c : word)
        {
            res |= 1 << (c - 'a');
        }
        return res;
    }
};
// @lc code=end

// TLE
// class Solution
// {
// public:
//     vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
//     {
//         unordered_map<char, unordered_map<string, int>> in_char_count_num;
//         unordered_map<string, vector<int>> char_count2index;
//         int index = 0;
//         for (auto &puzzle : puzzles)
//         {
//             string char_count(26, 0);
//             for (int i = 0; i != 7; ++i)
//             {
//                 char_count[puzzle[i] - 'a'] = 1;
//             }
//             char_count.push_back(puzzle[0]);
//             in_char_count_num[puzzle[0]][char_count];
//             char_count2index[char_count].push_back(index);
//             ++index;
//         }
//         for (auto &word : words)
//         {
//             for (int i = 0; i != 26; ++i)
//             {
//                 char c = 'a' + i;
//                 if (in_char_count_num.count(c) && word.find(c) != -1)
//                 {
//                     for (auto &p : in_char_count_num[c])
//                     {
//                         if (is_in(word, p.first))
//                         {
//                             ++p.second;
//                         }
//                     }
//                 }
//             }
//         }
//         vector<int> res(index);
//         for (auto &char2char_count : in_char_count_num)
//         {
//             for (auto &char_count2num : char2char_count.second)
//             {
//                 if (char_count2num.second)
//                 {
//                     for (auto ind : char_count2index[char_count2num.first])
//                     {
//                         res[ind] += char_count2num.second;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
//     bool is_in(const string &s, const string &char_count)
//     {
//         for (int i = 0; i != 26; ++i)
//         {
//             char c = 'a' + i;
//             if (s.find(c) != -1 && char_count[i] == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// }
// }
// ;

// class Solution
// {
// public:
//     vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
//     {
//         unordered_map<char, unordered_map<int, int>> first_char2in_string2count;
//         unordered_map<int, unordered_map<char, vector<int>>> string2first_char2index;
//         int index = 0;
//         for (auto &puzzle : puzzles)
//         {
//             int char_count = 0;
//             for (int i = 0; i != 7; ++i)
//             {
//                 char_count |= 1 << (puzzle[i] - 'a');
//             }
//             first_char2in_string2count[puzzle[0]][char_count] = 0;
//             string2first_char2index[char_count][puzzle[0]].push_back(index);
//             ++index;
//         }
//         for (auto &word : words)
//         {
//             int word_char_count = 0;
//             for (auto c : word)
//             {
//                 word_char_count |= 1 << (c - 'a');
//             }
//             // if (bit_count(word_char_count) > 7)
//             // {
//             //     continue;
//             // }
//             for (int i = 0; i != 26; ++i)
//             {
//                 if (word_char_count & (1 << i))
//                 {
//                     if (first_char2in_string2count.count('a' + i))
//                     {
//                         for (auto &char_count_string_pair : first_char2in_string2count['a' + i])
//                         {
//                             if (is_in(word_char_count, char_count_string_pair.first))
//                             {
//                                 char_count_string_pair.second += 1;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         vector<int> res(index);
//         for (auto &first_char_pair : first_char2in_string2count)
//         {
//             for (auto &char_count_pair : first_char_pair.second)
//             {
//                 if (char_count_pair.second)
//                 {
//                     for (auto ind : string2first_char2index[char_count_pair.first][first_char_pair.first])
//                     {
//                         res[ind] += char_count_pair.second;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
//     bool is_in(int s, int char_count)
//     {
//         return !(s & ~char_count);
//     }
//     int bit_count(int n)
//     {
//         int res = 0;
//         while (n)
//         {
//             if (n % 2)
//             {
//                 ++res;
//             }
//             n >>= 1;
//         }
//         return res;
//     }
// };