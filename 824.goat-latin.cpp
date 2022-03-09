/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    string vowel = {'a', 'e', 'i', 'o', 'u'};

public:
    string toGoatLatin(string sentence)
    {
        string res;
        sentence.push_back(' ');
        int len = sentence.size();
        short count = 1;
        for (int i = 0; i != len; ++i)
        {
            if (vowel.find_first_of(tolower(sentence[i])) != -1)
            {
                while (sentence[i] != ' ')
                {
                    res.push_back(sentence[i]);
                    ++i;
                }
                res.append("ma");
                res.append(string(count++, 'a'));
                res.push_back(' ');
            }
            else
            {
                char reserve_char = sentence[i++];
                while (sentence[i] != ' ')
                {
                    res.push_back(sentence[i]);
                    ++i;
                }
                res.push_back(reserve_char);
                res.append("ma");
                res.append(string(count++, 'a'));
                res.push_back(' ');
            }
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
