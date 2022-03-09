/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> diff_ind;
        for (int i = 0, width = s1.size(); i != width; ++i)
        {
            if (s1[i] != s2[i])
            {
                if (diff_ind.size() == 2)
                {
                    return false;
                }
                diff_ind.push_back(i);
            }
        }
        if (diff_ind.size() == 0)
        {
            return true;
        }
        else if (diff_ind.size() == 1)
        {
            return false;
        }
        else
        {
            return s1[diff_ind[0]] == s2[diff_ind[1]] && s1[diff_ind[1]] == s2[diff_ind[0]];
        }
    }
};
// @lc code=end
