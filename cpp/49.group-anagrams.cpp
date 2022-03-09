/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hmap;
        vector<vector<string>> res;
        for (auto &s : strs)
        {
            // string bs(26,' ');
            // for (auto &w : s)
            // {
            //     bs[(w - 'a')]++;
            // }
            auto bs=s;
            sort(bs.begin(),bs.end());
            hmap[bs].push_back(s);
        }
        for (auto &s : hmap)
        {
            res.push_back(s.second);
        }
        return res;
    }
};
// @lc code=end

