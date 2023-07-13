/*
 * @lc app=leetcode id=1954 lang=cpp
 *
 * [1954] Minimum Garden Perimeter to Collect Enough Apples
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(n^(1/3)), s:O(1);
class Solution
{

public:
    long long minimumPerimeter(long long neededApples)
    {
        long long n = 1;
        while (2 * n * (n + 1) * (2 * n + 1) < neededApples)
        {
            ++n;
        }
        return n * 8;
    }
};
// @lc code=end
