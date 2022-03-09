/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, vector<char>> allowed_collection;
    unordered_set<string> false_record;

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (auto &elem : allowed)
        {
            allowed_collection[elem.substr(0, 2)].push_back(elem[2]);
        }
        return helpler(bottom, "");
    }
    bool helpler(string current_level, string up_level)
    {
        if (false_record.count(current_level))
        {
            return false;
        }
        if (current_level.size() == 1)
        {
            return true;
        }
        int up_level_len = up_level.size();
        if (up_level_len == current_level.size() - 1)
        {
            return helpler(up_level, "");
        }
        for (char c : allowed_collection[current_level.substr(up_level_len, 2)])
        {
            if (helpler(current_level, up_level + c))
            {
                return true;
            }
        }
        false_record.insert(current_level);
        return false;
    }
};
// @lc code=end