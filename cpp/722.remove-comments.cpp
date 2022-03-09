/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        bool is_comment = false;
        vector<string> new_source;
        for (auto &src : source)
        {
            auto prev_is_comment = is_comment;
            src = helpler(src, is_comment);
            if (prev_is_comment && !is_comment)
            {
                new_source.back().append(src);
            }
            else if (src != "")
            {
                new_source.push_back(src);
            }
        }
        return new_source;
    }
    string helpler(string src, bool &is_comment)
    {
        if (is_comment)
        {
            int end_comment_pos = src.find("*/");
            if (end_comment_pos != -1)
            {
                is_comment = false;
                return helpler(src.substr(end_comment_pos + 2), is_comment);
            }
            else
            {
                return "";
            }
        }
        else
        {
            size_t start_comment_pos = src.find("/*");
            size_t start_line_comment_pos = src.find("//");
            if (start_line_comment_pos < start_comment_pos)
            {
                return src.substr(0, start_line_comment_pos);
            }
            else if (start_comment_pos != -1)
            {
                is_comment = true;
                return src.substr(0, start_comment_pos) + helpler(src.substr(start_comment_pos + 2), is_comment);
            }
            else
            {
                return src;
            }
        }
    }
};
// @lc code=end