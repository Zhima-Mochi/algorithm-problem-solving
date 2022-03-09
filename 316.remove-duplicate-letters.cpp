/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> count(26);
        vector<bool> existed(26);
        for (auto c : s)
        {
            ++count[c - 'a'];
        }
        string res;
        for (auto c : s)
        {
            --count[c - 'a'];
            if (existed[c - 'a'])
            {
                continue;
            }
            else
            {
                while (!res.empty() && res.back() > c && count[res.back() - 'a'])
                {
                    existed[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                existed[c - 'a'] = true;
            }
        }
        return res;
    }
};
// @lc code=end
