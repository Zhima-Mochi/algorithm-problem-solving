/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
#define mod 1000000007
class Solution
{
    unordered_map<int, int> record;

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long res = 0;
        for (auto n : arr)
        {
            long long count = 1;
            for (auto &&p : record)
            {
                if (n % p.first == 0 && record.count(n / p.first))
                {
                    count += static_cast<long>(p.second) * record[n / p.first];
                }
            }
            record[n] = count % mod;
            res += record[n];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end
