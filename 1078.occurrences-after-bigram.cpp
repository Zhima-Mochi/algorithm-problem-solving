/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        text.push_back(' ');
        bool find_first = false;
        bool match = false;
        vector<string> res;
        int pos = 0;
        int len = text.size();
        while (pos != len)
        {
            auto next_pos = text.find(' ', pos);
            if (match)
            {
                res.push_back(text.substr(pos, next_pos - pos));
                match=false;
            }
            if (!find_first)
            {
                if (text.substr(pos, next_pos - pos) == first)
                {
                    find_first = true;
                }
                pos = next_pos + 1;
            }
            else
            {
                if (text.substr(pos, next_pos - pos) == second)
                {
                    match = true;
                    if (second != first)
                    {
                        find_first = false;
                    }
                }
                else if (text.substr(pos, next_pos - pos) != first)
                {
                    find_first = false;
                }
                pos = next_pos + 1;
            }
        }
        return res;
    }
};
// @lc code=end
