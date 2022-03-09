/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    unordered_set<char> key_char = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:
    bool halvesAreAlike(string s)
    {
        int half_width = s.size() / 2;
        int count_num = 0;
        for (int i = 0; i != half_width; ++i)
        {
            if (key_char.count(s[i]))
            {
                ++count_num;
            }
        }
        for (int i = half_width; i != 2 * half_width; ++i)
        {
            if (key_char.count(s[i]))
            {
                --count_num;
            }
        }
        return count_num == 0;
    }
};
// @lc code=end
