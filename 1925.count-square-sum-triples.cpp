/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countTriples(int n)
    {

        int res = 0;
        for (int i = 1; i <= n - 2; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                auto square_value = i * i + j * j;
                int root = sqrt(square_value);
                if (root > n)
                {
                    break;
                }
                if (root * root == square_value)
                {
                    ++res;
                }
            }
        }
        return res * 2;
    }
};
// @lc code=end