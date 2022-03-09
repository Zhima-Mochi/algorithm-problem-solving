/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<vector<int>> alpha_pos(26, {-1, -1});
        int ind = 0;
        for (auto c : s)
        {
            if (alpha_pos[c - 'a'][0] == -1)
            {
                alpha_pos[c - 'a'][0] = ind;
                alpha_pos[c - 'a'][1] = ind;
            }
            else
            {
                alpha_pos[c - 'a'][1] = ind;
            }
            ++ind;
        }
        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0, width = s.size(); i != width; ++i)
        {
            right = max(alpha_pos[s[i] - 'a'][1], right);
            if (right == i)
            {
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};
// @lc code=end
