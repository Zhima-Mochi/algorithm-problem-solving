/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int lower_num = 0, upper_num = s.size();
        vector<int> res;
        res.reserve(upper_num + 1);
        for (auto c : s)
        {
            if (c == 'I')
            {
                res.push_back(lower_num++);
            }
            else
            {
                res.push_back(upper_num--);
            }
        }
        res.push_back(lower_num);
        return res;
    }
};
// @lc code=end
