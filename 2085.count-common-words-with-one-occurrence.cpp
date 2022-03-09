/*
 * @lc app=leetcode id=2085 lang=cpp
 *
 * [2085] Count Common Words With One Occurrence
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<string, int> m1, m2;
        for (auto &&word : words1)
        {
            ++m1[word];
        }
        for (auto &&word : words2)
        {
            ++m2[word];
        }
        int res = 0;
        for (auto &&p : m1)
        {
            if (p.second == 1 && m2.count(p.first) && m2[p.first] == 1)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
