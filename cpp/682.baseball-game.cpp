/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> v;
        for (auto &s : ops)
        {
            if (s == "C")
            {
                v.pop_back();
            }
            else if (s == "D")
            {
                v.push_back(*prev(v.end()) * 2);
            }
            else if (s == "+")
            {
                v.push_back(*prev(v.end()) + *prev(v.end(), 2));
            }
            else
            {
                v.push_back(stoi(s));
            }
        }
        int res = 0;
        for (auto &val : v)
        {
            res += val;
        }
        return res;
    }
};
// @lc code=end
