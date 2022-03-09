/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string customSortString(string order, string str)
    {
        short mp[26]={0};
        int count = 1;
        for (auto &a : order)
        {
            mp[a - 'a'] = count;
            ++count;
        }
        sort(str.begin(), str.end(), [mp](char l, char r)
             { return mp[l - 'a'] < mp[r - 'a']; });
        return str;
    }
};
// @lc code=end
//"kqep"\n"pekeq"\n