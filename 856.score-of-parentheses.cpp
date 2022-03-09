/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int res = 0;
        int left = 0;
        for (int i = 0, w = s.size(); i != w; ++i)
        {
            if (s[i] == '(')
            {
                ++left;
            }
            else
            {
                --left;
                if (s[i - 1] == '(')
                {
                    res += 1 << left;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// t:O(n), s:O(n)
// class Solution
// {
// public:
//     int scoreOfParentheses(string s)
//     {
//         vector<int> vec = {0};
//         for (auto c : s)
//         {
//             if (c == '(')
//             {
//                 vec.push_back(0);
//             }
//             else
//             {
//                 int val = vec.back();
//                 if (val == 0)
//                 {
//                     val = 1;
//                 }
//                 vec.pop_back();
//                 vec.back() += 2 * val;
//             }
//         }
//         return vec[0] / 2;
//     }
// };