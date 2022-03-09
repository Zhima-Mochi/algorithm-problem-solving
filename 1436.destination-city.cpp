/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> depart_place;
        for (auto &pr : paths)
        {
            depart_place.insert(pr[0]);
        }
        for (auto &pr : paths)
        {
            if (!depart_place.count(pr[1]))
            {
                return pr[1];
            }
        }
        return "";
    }
};
// @lc code=end
