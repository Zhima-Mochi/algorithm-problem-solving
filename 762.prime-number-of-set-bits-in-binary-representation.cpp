/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

public:
    int countPrimeSetBits(int left, int right)
    {
        return helpler(right) - helpler(left - 1);
    }
    int helpler(int num)
    {
        int start = 31;
        int pre_one_bit = 0;
        int prime_count = 0;
        while (start)
        {
            if ((1 << (start - 1)) & num)
            {
                for (auto &p : prime)
                {
                    if (p - pre_one_bit == 1)
                    {
                        ++prime_count;
                    }
                    else if (p <= pre_one_bit)
                    {
                        continue;
                    }
                    else if (p - pre_one_bit >= start)
                    {
                        break;
                    }
                    prime_count += c_select(start - 1, p - pre_one_bit);
                }
                ++pre_one_bit;
            }
            --start;
        }
        return prime_count;
    }
    int c_select(int total, int pick)
    {
        int count = pick;
        long res = 1;
        while (count--)
        {
            res *= (total - count);
        }
        while (pick)
        {
            res /= pick--;
        }
        return res;
    }
};
// @lc code=end
