/*
 * @lc app=leetcode id=1994 lang=cpp
 *
 * [1994] The Number of Good Subsets
 */
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
int mod = 1000000007;
class Solution
{
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        vector<int> count(31);
        vector<int> bit_represent(31);
        int w = nums.size();
        for (auto n : nums)
        {
            if (n % 4 == 0 || n % 9 == 0 || n == 25)
            {
                continue;
            }
            ++count[n];
            if (bit_represent[n] == 0)
            {
                int m=n;
                for (auto p : primes)
                {
                    if (m % p == 0)
                    {
                        bit_represent[n] |= (1 << p);
                        m /= p;
                    }
                    if (m == 1)
                    {
                        break;
                    }
                }
            }
        }
        long long res = 0;
        long long base_num = 1;
        while (count[1])
        {
            if (count[1] > 30)
            {
                base_num <<= 30;
                base_num %= mod;
                count[1] -= 30;
            }
            else
            {
                base_num <<= count[1];
                base_num %= mod;
                count[1] = 0;
            }
        }
        function<void(int, int, long long)> backtracking = [&](int idx, int bit_record, long long val)
        {
            if (idx == 31)
            {
                res += (base_num * val) % mod;
                res %= mod;
                return;
            }
            backtracking(idx + 1, bit_record, val);
            if (count[idx] != 0)
            {
                if (bit_record == 0)
                {
                    val = count[idx];
                    bit_record = bit_represent[idx];
                    backtracking(idx + 1, bit_record, val);
                }
                else if ((bit_represent[idx] & bit_record) == 0)
                {
                    val *= count[idx];
                    val %= mod;
                    bit_record |= bit_represent[idx];
                    backtracking(idx + 1, bit_record, val);
                }
            }
        };
        backtracking(2, 0, 0);
        return res;
    }
};
// @lc code=end