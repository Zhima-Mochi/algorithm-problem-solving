/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start

// Information theorem
// log_2(times+1) bit information per pig
// log_2(buckets) bit total information 
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int times = minutesToTest / minutesToDie;
        int res = ceil(log(buckets) / log(times + 1));
        return res;
    }
};
// @lc code=end
