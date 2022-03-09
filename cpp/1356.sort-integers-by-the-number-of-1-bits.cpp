/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [](int l, int r)
             { return make_pair(countOneBit(l), l) < make_pair(countOneBit(r), r); });
        return arr;
    }
    static int countOneBit(int n)
    {
        int count = 0;
        while (n)
        {
            if (n & 1)
            {
                ++count;
            }
            n >>= 1;
        }
        return count;
    }
};
// @lc code=end
