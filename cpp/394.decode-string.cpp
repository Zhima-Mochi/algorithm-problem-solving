/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        string res;
        stack<int> repeat_time;
        stack<string> repeat_word;
        int width = s.size();
        auto pos = 0;
        while (pos != width)
        {
            if (isalpha(s[pos]))
            {
                if (repeat_word.empty())
                {
                    res.push_back(s[pos]);
                }
                else
                {
                    repeat_word.top().push_back(s[pos]);
                }
                ++pos;
            }
            else if (isdigit(s[pos]))
            {
                int num = s[pos] - '0';
                while (isdigit(s[++pos]))
                {
                    num *= 10;
                    num += s[pos] - '0';
                }
                repeat_time.push(num);
            }
            else if (s[pos] == '[')
            {
                repeat_word.push("");
                ++pos;
            }
            else
            {
                string last_str = repeat_word.top();
                repeat_word.pop();
                if (!repeat_word.empty())
                {
                    repeat(repeat_word.top(), last_str, repeat_time.top());
                }
                else
                {
                    repeat(res, last_str, repeat_time.top());
                }
                repeat_time.pop();
                ++pos;
            }
        }
        return res;
    }
    void repeat(string &org, string &str, int num)
    {
        org.reserve(org.size() + str.size() * num);
        while (num)
        {
            org.append(str);
            --num;
        }
    }
};
// @lc code=end
