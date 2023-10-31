/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */
#include<unordered_map>
#include<cmath>
using namespace std;

// @lc code=start
class Solution
{
    unordered_map<int, int> record;

public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int times = minutesToTest / minutesToDie;
        int res = ceil(log(buckets) / log(times + 1) - 1e-5);
        return res;
    }
};
// @lc code=end

