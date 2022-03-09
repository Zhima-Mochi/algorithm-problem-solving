/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(len(s)), s:O(1)
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        int w = s.size();
        long long current_len = 0;
        int idx = 0;
        while (idx != w)
        {
            if (!isdigit(s[idx]))
            {
                ++current_len;
                if (current_len == k)
                {
                    return string{s[idx]};
                }
                ++idx;
            }
            else
            {
                if (current_len * (s[idx] - '0') >= k)
                {
                    current_len *= (s[idx] - '0');
                    for (int i = idx; i != -1; --i)
                    {
                        k %= current_len;
                        if (isdigit(s[i]))
                        {
                            current_len /= s[i] - '0';
                        }
                        else if (k == 0)
                        {
                            return string{s[i]};
                        }
                        else
                        {
                            --current_len;
                        }
                    }
                }
                else
                {
                    current_len *= (s[idx] - '0');
                    ++idx;
                }
            }
        }
        return "";
    }
};
// @lc code=end

// t:O(len(s)), s:O(1)
// class Solution
// {
// public:
//     string decodeAtIndex(string s, int k)
//     {
//         int w = s.size();
//         long long current_len = 0;
//         for (auto c : s)
//         {
//             if (!isdigit(c))
//             {
//                 ++current_len;
//             }
//             else
//             {
//                 current_len *= c - '0';
//             }
//         }
//         for (int i = w - 1; i != -1; --i)
//         {
//             k %= current_len;
//             if (isdigit(s[i]))
//             {
//                 current_len /= (s[i] - '0');
//             }
//             else if (k == 0)
//             {
//                 return string{s[i]};
//             }
//             else
//             {
//                 --current_len;
//             }
//         }
//         return "";
//     }
// };