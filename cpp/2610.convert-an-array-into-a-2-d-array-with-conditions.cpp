/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> uq;
        for (auto n : nums)
        {
            mp[n]++;
            if (mp[n] == 1)
            {
                uq.push_back(n);
            }
        }
        sort(uq.begin(), uq.end(), [&](int a, int b)
             { return mp[a] > mp[b]; });
        vector<vector<int>> ans;
        while (!uq.empty())
        {
            ans.push_back(vector<int>());
            int l = uq.size();
            for (int i = 0; i != l; ++i)
            {
                ans.back().push_back(uq[i]);
                mp[uq[i]]--;
            }
            while (!uq.empty() && mp[uq.back()] == 0)
            {
                uq.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end
