/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> ratio_map;
        auto val_iter = values.begin();
        for (auto &eq : equations)
        {
            ratio_map[eq[0]][eq[1]] = *val_iter;
            ratio_map[eq[1]][eq[0]] = 1 / *val_iter;
            ++val_iter;
        }
        vector<double> res;
        for (auto &query : queries)
        {
            if (!ratio_map.count(query[1]))
            {
                res.push_back(-1);
                continue;
            }
            else
            {
                unordered_set<string> used;
                res.push_back(dfs(ratio_map, used, query[0], query[1]));
            }
        }
        return res;
    }
    double dfs(unordered_map<string, unordered_map<string, double>> &ratio_map, unordered_set<string> &used, const string &first, const string &second)
    {

        if (!ratio_map.count(first))
        {
            return -1;
        }
        else
        {
            if (ratio_map[first].count(second))
            {
                return ratio_map[first][second];
            }
            used.insert(first);
            for (auto &pair : ratio_map[first])
            {
                if (used.count(pair.first))
                {
                    continue;
                }
                auto val = dfs(ratio_map, used, pair.first, second);
                if (val != -1)
                {
                    //ratio_map[first][second] = val * pair.second;
                    return val * pair.second;
                }
            }
            used.erase(first);
            //ratio_map[first][second] = -1;
            return -1;
        }
    }
};
// @lc code=end
