/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */
#include <vector>
using namespace std;
// @lc code=start
//  t:O(N^2), s:O(1)
class Solution
{
    int mod = 1000000007;

public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        long long res = 0;
        vector<int> record(301);
        int w = arr.size();
        for (int j = 1; j != w - 1; ++j)
        {
            ++record[arr[j - 1]];
            int sub_target = target - arr[j];
            if (sub_target >= 0)
            {
                for (int k = j + 1; k != w; ++k)
                {
                    if (sub_target - arr[k] >= 0)
                    {
                        res += record[sub_target - arr[k]];
                    }
                }
                res %= mod;
            }
        }
        return res;
    }
};
// @lc code=end
