/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iterator>
using namespace std;
// @lc code=start
class Solution
{
public:
    string multiply(string &num1, string &num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int len1, len2;
        len1 = num1.size();
        len2 = num2.size();
        int totalLen = len1 + len2 - 1;
        string res;
        vector<short> mulArr(totalLen, 0);
        for (int i = 0; i != len1; i++)
        {
            for (int j = 0; j != len2; j++)
            {
                mulArr[totalLen - 1 - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        mulArr.push_back(0);
        for (int i = 0; i != totalLen; i++)
        {
            if (mulArr[i] / 10)
            {
                mulArr[i + 1] += mulArr[i] / 10;
                mulArr[i] %= 10;
            }
        }
        if (mulArr.back() == 0)
        {
            mulArr.pop_back();
        }

        transform(mulArr.rbegin(), mulArr.rend(), back_inserter(res), [](int i)
                  { return '0' + i; });
        return res;
    }
};
// @lc code=end
