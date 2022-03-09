/*
 * @lc app=leetcode id=2103 lang=cpp
 *
 * [2103] Rings and Rods
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(rings.size()+10) s:O(10)
class Solution
{
public:
    int countPoints(string rings)
    {
        vector<int> record(10);
        for (int i = 0, w = rings.size(); i != w; i += 2)
        {
            if (rings[i] == 'R')
            {
                record[rings[i + 1] - '0'] |= 1;
            }
            else if (rings[i] == 'G')
            {
                record[rings[i + 1] - '0'] |= 2;
            }
            else
            {
                record[rings[i + 1] - '0'] |= 4;
            }
        }
        int res = 0;
        for (auto n : record)
        {
            if (n == 7)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
