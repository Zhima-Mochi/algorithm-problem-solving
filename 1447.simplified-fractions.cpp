/*
 * @lc app=leetcode id=1447 lang=cpp
 *
 * [1447] Simplified Fractions
 */
#include <vector>
#include <string>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(n^2log(n)), s:O(n^2)
class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> res;
        for (int i = 2; i != n + 1; ++i)
        {
            if (i % 2)
            {
                for (int j = 1; j != i; ++j)
                {
                    if (gcd(i, j) == 1)
                    {
                        res.push_back(to_string(j) + '/' + to_string(i));
                    }
                }
            }
            else
            {
                for (int j = 1; j < i; j += 2)
                {
                    if (gcd(i, j) == 1)
                    {
                        res.push_back(to_string(j) + '/' + to_string(i));
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
