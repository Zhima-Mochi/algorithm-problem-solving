/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, int> record;

public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        for (auto &&cpdomain : cpdomains)
        {
            int pos = cpdomain.find(' ');
            int num = stoi(cpdomain.substr(0, pos));
            record[cpdomain.substr(pos + 1)] += num;
            while ((pos = cpdomain.find('.', pos + 1)) != -1)
            {
                record[cpdomain.substr(pos + 1)] += num;
            }
        }
        vector<string> res;
        for (auto &&p : record)
        {
            res.push_back(to_string(p.second) + ' ' + p.first);
        }
        return res;
    }
};
// @lc code=end
