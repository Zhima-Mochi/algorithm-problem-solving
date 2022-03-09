/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        unordered_map<string, pair<string, string>> umap;
        int len = logs.size();
        for (int i = 0; i != len; ++i)
        {
            int pos = logs[i].find(' ');
            if (isdigit(logs[i][pos + 1]))
            {
                umap[logs[i]] = {string(1, 'z' + 1), string(1, i)};
            }
            else
            {
                umap[logs[i]] = {logs[i].substr(pos + 1), logs[i].substr(0, pos)};
            }
        }
        auto comp = [&umap](string &l, string &r)
        {
            return umap[l] < umap[r];
        };
        sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};
// @lc code=end