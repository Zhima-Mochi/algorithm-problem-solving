/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> res;
        res.reserve(n);
        if (rounds.back() >= rounds.front())
        {
            for (int i = rounds.front(); i != rounds.back() + 1; ++i)
            {
                res.push_back(i);
            }
            return res;
        }
        else
        {
            for (int i = 1; i != rounds.back() + 1; ++i)
            {
                res.push_back(i);
            }
            for (int i = rounds.front(); i != n + 1; ++i)
            {
                res.push_back(i);
            }
            return res;
        }
        return res;
    }
};
// @lc code=end
