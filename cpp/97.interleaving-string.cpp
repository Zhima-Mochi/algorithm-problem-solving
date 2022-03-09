/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        auto len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3)
        {
            return false;
        }
        vector<bool> check(len2 + 1, false);
        check[0] = true;
        for (int j = 1; j != len2 + 1; ++j)
        {
            if (check[j - 1] == true && s2[j - 1] == s3[j - 1])
            {
                check[j] = true;
            }
            else
            {
                check[j] = false;
                break;
            }
        }
        for (int i = 1; i != len1 + 1; ++i)
        {
            for (int j = 0; j != len2 + 1; ++j)
            {
                if (j == 0)
                {
                    if (check[0] == true && s1[i - 1] == s3[i - 1])
                    {
                        check[j] = true;
                    }
                    else
                    {
                        check[j] = false;
                    }
                }
                else if (check[j] == true && s1[i - 1] == s3[i + j - 1])
                {
                    check[j] = true;
                }
                else if (check[j - 1] == true && s2[j - 1] == s3[i + j - 1])
                {
                    check[j] = true;
                }
                else
                {
                    check[j] = false;
                }
            }
        }
        return check[len2];
    };
};
// @lc code=end
//"aa"\n"ab"\n"aaba"\n "aa"\n"ab"\n"abaa"\n "aabcc"\n"dbbca"\n"aadbbcbcac"\n "db"\n"b"\n"cbb"\n "aa"\n"ab"\n"aaab"\n "aabd"\n"abdc"\n"aabdabcd"\n "aabd"\n"abdc"\n"aabdbadc"\n  "aabc"\n"abad"\n"aabadabc"\n