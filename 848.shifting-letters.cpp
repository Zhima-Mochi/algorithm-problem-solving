/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int len = s.size();
        int shift = 0;
        for (int i = len - 1; i != -1; --i)
        {
            shift += shifts[i];
            shift %= 26;
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
        }
        return s;
    }
};
// @lc code=end
