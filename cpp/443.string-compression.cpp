/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        chars.push_back(0);
        int len = chars.size();
        if (len == 1)
        {
            return 1;
        }
        int same_count = 1;
        int cur = 0;
        for (int i = 1; i != len; ++i)
        {
            if (chars[i] == chars[i - 1])
            {
                ++same_count;
            }
            else
            {
                chars[cur] = chars[i - 1];
                ++cur;
                if (same_count > 1)
                {
                    int sub_len = 0;
                    while (same_count)
                    {
                        ++sub_len;
                        chars[cur] = '0' + same_count % 10;
                        ++cur;
                        same_count /= 10;
                    }
                    reverse(chars.begin() + cur - sub_len, chars.begin() + cur);
                }
                same_count = 1;
            }
        }
        return cur;
    }
};
// @lc code=end
