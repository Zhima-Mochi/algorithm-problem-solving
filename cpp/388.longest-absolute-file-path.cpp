/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stack<int> lengths;
        lengths.push(0);
        int len = input.size();
        auto pos = 0;
        auto address_len = 0;
        int res = 0;
        while (true)
        {
            bool is_file = false;

            auto next_pos = pos;
            while (input[next_pos] != '\n' && next_pos < len)
            {
                if (input[next_pos] == '.')
                {
                    is_file = true;
                }
                ++next_pos;
            }

            if (next_pos != len)
            {
                address_len += next_pos - pos + 1;
                int next_depth = 0;
                while (input[next_pos + 1] == '\t')
                {
                    ++next_pos;
                    ++next_depth;
                }
                if (next_depth > lengths.size()-1)
                {
                    lengths.push(address_len);
                }
                else
                {
                    if (is_file)
                    {
                        res = max(res, address_len - 1);
                    }
                    while (lengths.size()-1 > next_depth)
                    {
                        lengths.pop();
                    }
                    address_len = lengths.top();
                }
                pos = next_pos + 1;
            }
            else
            {
                address_len += len - pos;
                if (is_file)
                {
                    res = max(res, address_len);
                }
                break;
            }
        }
        return res;
    }
};
// @lc code=end
