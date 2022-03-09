/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        int width = s.size();
        vector<string> res_collection = {s};
        for (int i = 0; i != width; ++i)
        {
            if (isalpha(s[i]))
            {
                char new_ch = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]);
                int collection_len = res_collection.size();
                for (int j = 0; j != collection_len; ++j)
                {
                    res_collection.push_back(res_collection[j]);
                    res_collection.back()[i] = new_ch;
                }
            }
        }
        return res_collection;
    }
};
// @lc code=end
