/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    string vowels = "aeiouAEIOU";

public:
    string sortVowels(string s)
    {
        string v;
        for (auto c : s)
        {
            if (vowels.find(c) != string::npos)
            {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end(), greater<char>());
        int n = s.size();
        for (int i = 0; i != n; ++i)
        {
            if (vowels.find(s[i]) != string::npos)
            {
                s[i] = v.back();
                v.pop_back();
            }
        }
        return s;
    }
};
// @lc code=end
