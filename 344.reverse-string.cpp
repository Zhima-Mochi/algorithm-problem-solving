/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int len = s.size();
        for (int i = 0; i != len / 2; ++i)
        {
            swap(s[i],s[len-1-i]);
        }
    }
};
// @lc code=end
