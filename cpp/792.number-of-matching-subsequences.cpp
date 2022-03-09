/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<pair<int, int>>> candidates(26);
        for (int i = 0, width = words.size(); i != width; ++i)
        {
            candidates[words[i][0] - 'a'].push_back({i, 0});
        }
        int res = 0;
        for (auto c : s)
        {
            vector<pair<int, int>> old = candidates[c - 'a'];
            candidates[c - 'a'].clear();
            for (auto &&candidate : old)
            {
                candidate.second += 1;
                if (candidate.second == words[candidate.first].size())
                {
                    ++res;
                }
                else
                {
                    candidates[words[candidate.first][candidate.second] - 'a'].push_back(candidate);
                }
            }
        }
        return res;
    }
};
// @lc code=end
