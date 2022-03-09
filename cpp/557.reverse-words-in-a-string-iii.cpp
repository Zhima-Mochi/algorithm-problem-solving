/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        s.push_back(' ');
        auto pos = 0;
        while (pos != -1)
        {
            auto next_blank = s.find_first_of(' ', pos);
            reverse(s.begin() + pos, s.begin() + next_blank);
            pos = s.find_first_not_of(' ', next_blank);
        }
        s.pop_back();
        return s;
    }
};
// @lc code=end
