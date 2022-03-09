/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> required_words;
        int count_t = t.size();
        int width_s = s.size();
        for (auto c : t)
        {
            ++required_words[c];
        }
        int head = 0, tail = 0;
        int res_head = 0;
        int res_tail = INT_MAX;
        while (tail != width_s)
        {
            while (count_t)
            {
                if (tail == width_s)
                {
                    break;
                }
                if (required_words.count(s[tail]) && required_words[s[tail]]-- > 0)
                {
                    --count_t;
                }
                ++tail;
            }
            if (count_t > 0)
            {
                break;
            }
            while (count_t == 0)
            {
                if (required_words.count(s[head]) && ++required_words[s[head]] > 0)
                {
                    ++count_t;
                }
                ++head;
            }
            if (tail - head + 1 < res_tail - res_head)
            {
                res_tail = tail;
                res_head = head - 1;
            }
        }
        return res_tail == INT_MAX ? "" : s.substr(res_head, res_tail - res_head);
    }
};
// @lc code=end
