/*
 * @lc app=leetcode id=1534 lang=cpp
 *
 * [1534] Count Good Triplets
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int width = arr.size();
        int res = 0;
        for (int i = 0; i != width - 2; ++i)
        {
            for (int j = i + 1; j != width - 1; ++j)
            {
                if (abs(arr[i] - arr[j]) > a)
                {
                    continue;
                }
                for (int k = j + 1; k != width; ++k)
                {
                    if (abs(arr[k] - arr[i]) <= c && abs(arr[k] - arr[j]) <= b)
                    {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
