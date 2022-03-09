/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        vector<int> rd(1001, -1);
        int pos = 0;
        for (auto idx : indices)
        {
            rd[idx] = pos;
            ++pos;
        }
        string res;
        int prev_ind = 0;
        int count = 0;
        for (int index = 0, w = s.size(); index != w; ++index)
        {
            if (rd[index] == -1)
            {
                continue;
            }
            auto ind_width = sources[rd[index]].size();
            bool match = true;
            for (int i = 0; i != ind_width; ++i)
            {
                if (s[index + i] != sources[rd[index]][i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                res.append(s.substr(prev_ind, index - prev_ind));
                prev_ind = index + ind_width;
                res.append(targets[rd[index]]);
            }
            ++count;
        }
        res.append(s.substr(prev_ind, s.size() - prev_ind));
        return res;
    }
};
// @lc code=end
