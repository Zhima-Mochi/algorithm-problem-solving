/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), [](string &l, string &r)
             {
                 if (l.size() > r.size())
                 {
                     return true;
                 }
                 else if (l.size() == r.size())
                 {
                     return l < r;
                 }
                 else
                 {
                     return false;
                 }
             });
        for (auto &comp_str : dictionary)
        {
            if (isSubstring(s, comp_str))
            {
                return comp_str;
            }
        }
        return "";
    }
    bool isSubstring(string &s, string &comp_str)
    {
        if (s.length() < comp_str.length())
        {
            return false;
        }
        int pos = 0;
        for (auto c : comp_str)
        {
            int next_pos = s.find(c, pos);
            if (next_pos == -1)
            {
                return false;
            }
            pos = next_pos + 1;
        }
        return true;
    }
};
// @lc code=end
