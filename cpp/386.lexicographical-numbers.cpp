/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        int value = 1;
        while (res.size() != n)
        {
            if (value <= n)
            {
                res.push_back(value);
                value *= 10;
            }
            else
            {
                value /= 10;
                while (value % 10 == 9)
                {
                    value /= 10;
                }
                ++value;
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     vector<int> lexicalOrder(int n)
//     {
//         vector<int> res;
//         res.reserve(n); //necessary to const reference
//         helpler(res, n, 0);
//         return res;
//     }
//     void helpler(vector<int> &res, const int &n, const int &num)
//     {
//         for (int i = num == 0 ? 1 : 0; i != 10; ++i)
//         {
//             if (10 * num + i > n)
//             {
//                 break;
//             }
//             res.push_back(10 * num + i);
//             helpler(res, n, res.back());
//         }
//     }
// };