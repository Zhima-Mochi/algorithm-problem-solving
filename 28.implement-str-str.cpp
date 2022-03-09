/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    static vector<int> KMPFailureFunction(string &s);

public:
    int strStr(string haystack, string needle)
    {
        auto needle_len = needle.size();
        if (needle_len == 0)
        {
            return 0;
        }
        auto KMPFailureFunctionVec = KMPFailureFunction(needle);
        auto len = haystack.size();

        for (int index = 0, needle_index = 0; index != len;)
        {
            if (needle[needle_index] == haystack[index])
            {
                needle_index++;
                if (needle_index == needle_len)
                {
                    return index - needle_len + 1;
                }
                index++;
            }
            else if (needle_index > 0)
            {
                needle_index = KMPFailureFunctionVec[needle_index - 1];
            }
            else
            {
                index++;
            }
        }
        return -1;
    }
};
vector<int> Solution::KMPFailureFunction(string &s)
{

    vector<int> res = {0};
    auto len = s.size();
    int jumpValue = 0;
    for (size_t i = 1; i != len;)
    {
        if (s[jumpValue] == s[i])
        {
            ++jumpValue;
            res.push_back(jumpValue);
            i++;
        }
        else if (jumpValue > 0)
        {
            jumpValue=res[jumpValue - 1];
        }
        else
        {
            res.push_back(0);
            i++;
        }
    }
    return res;
}

// @lc code=end
