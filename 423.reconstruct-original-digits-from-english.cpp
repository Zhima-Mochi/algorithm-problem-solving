/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> alpha(26, 0);
        for (auto c : s)
        {
            ++alpha[c - 'a'];
        }
        vector<int> count(10, 0);
        count[0] = alpha['z' - 'a'];
        count[2] = alpha['w' - 'a'];
        count[4] = alpha['u' - 'a'];
        count[6] = alpha['x' - 'a'];
        count[8] = alpha['g' - 'a'];
        count[1] = alpha['o' - 'a'];
        count[3] = alpha['h' - 'a'];
        count[7] = alpha['s' - 'a'];
        count[5] = alpha['v' - 'a'];
        count[9] = alpha['n' - 'a'];

        count[1] -= count[2] + count[4] + count[0];
        count[3] -= count[8];
        count[7] -= count[6];
        count[5] -= count[7];
        count[9] -= count[1] + count[7];
        count[9] /= 2;
        string res;
        for (int i = 0; i != 10; ++i)
        {
            for (int j = 0; j != count[i]; ++j)
            {
                res.push_back('0' + i);
            }
        }
        return res;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     string originalDigits(string s)
//     {
//         vector<int> count(10, 0);
//         for (auto c : s)
//         {
//             switch (c)
//             {
//             case 'z':
//                 ++count[0];
//                 break;
//             case 'w':
//                 ++count[2];
//                 break;
//             case 'u':
//                 ++count[4];
//                 break;
//             case 'x':
//                 ++count[6];
//                 break;
//             case 'g':
//                 ++count[8];
//                 break;
//             case 'o':
//                 ++count[1]; //- 2,4,0
//                 break;
//             case 'h':
//                 ++count[3]; //- 8
//                 break;
//             case 's':
//                 ++count[7]; //- 6
//                 break;
//             case 'v':
//                 ++count[5]; //- 7
//                 break;
//             case 'n':
//                 ++count[9]; //- 1,7 /2
//                 break;
//             default:
//                 break;
//             }
//         }
//         count[1] -= count[2] + count[4] + count[0];
//         count[3] -= count[8];
//         count[7] -= count[6];
//         count[5] -= count[7];
//         count[9] -= count[1] + count[7];
//         count[9] /= 2;
//         string res;
//         for (int i = 0; i != 10; ++i)
//         {
//             for (int j = 0; j != count[i]; ++j)
//             {
//                 res.push_back('0' + i);
//             }
//         }
//         return res;
//     }
// };