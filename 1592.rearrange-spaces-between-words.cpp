/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reorderSpaces(string text)
    {
        int word_num = 0;
        int blank_num = 0;
        int width = text.size();
        for (int i = 0; i != width; ++i)
        {
            if (isblank(text[i]))
            {
                ++blank_num;
                if (i > 0 && !isblank(text[i - 1]))
                {
                    ++word_num;
                }
            }
        }
        if(blank_num==0){
            return text;
        }
        if (!isblank(text[width - 1]))
        {
            ++word_num;
        }
        string window_str = word_num==1?"": string(blank_num / (word_num-1), ' ');
        string res;
        res.reserve(width);
        for (int i = 0; i != width; ++i)
        {
            if (isalpha(text[i]))
            {
                res.push_back(text[i]);
            }
            else if (i > 0 && isalpha(text[i - 1]))
            {
                res.append(window_str);
            }
        }
        res.resize(width,' ');
        return res;
    }
};
// @lc code=end
