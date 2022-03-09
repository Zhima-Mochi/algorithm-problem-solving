/*
 * @lc app=leetcode id=2047 lang=cpp
 *
 * [2047] Number of Valid Words in a Sentence
 */
#include <string>
#include <regex>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countValidWords(string sentence)
    {
        int pos = sentence.find_first_not_of(" ");
        int next_pos;
        sentence.push_back(' ');
        int res = 0;
        while ((next_pos = sentence.find(" ", pos)) != -1)
        {
            string s = sentence.substr(pos, next_pos - pos);
            bool match = true;
            int count = 0;
            for (int i = 0, width = s.size(); i != width; ++i)
            {
                if (i < width - 1 && (s[i] == '.' || s[i] == '!' || s[i] == ','))
                {
                    match = false;
                    break;
                }
                if (s[i] == '-')
                {
                    if (i == 0 || i == width - 1 || !isalpha(s[i + 1]) || count == 1)
                    {
                        match = false;
                        break;
                    }
                    ++count;
                }
                if (isdigit(s[i]))
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                ++res;
            }
            pos = sentence.find_first_not_of(" ", next_pos);
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
//     regex valid = regex("([a-z]+-[a-z]+|[a-z]+)[.!,]?|[.!,]");

// public:
//     int countValidWords(string sentence)
//     {
//         int pos = sentence.find_first_not_of(" ");
//         int next_pos;
//         sentence.push_back(' ');
//         int res = 0;
//         while ((next_pos = sentence.find(" ", pos)) != -1)
//         {
//             if (regex_match(sentence.substr(pos, next_pos - pos), valid))
//             {
//                 ++res;
//             }
//             pos = sentence.find_first_not_of(" ", next_pos);
//         }
//         return res;
//     }
// };