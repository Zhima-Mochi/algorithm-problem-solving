/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */
#include <vector>
using namespace std;
// @lc code=start
#define mod 1000000007
class Solution
{

    vector<long long> prev_status = {1, 1, 2, 5, 11};
    int num = 4;

public:
    int numTilings(int n)
    {
        long long root_val = 2;
        while (n > num)
        {
            ++num;
            prev_status[num % 5] = root_val + prev_status[(num + 1) % 5] * 2;
            prev_status[num % 5] %= mod;
            root_val = prev_status[num % 5];

            prev_status[num % 5] += prev_status[(num + 2) % 5] * 2;
            prev_status[num % 5] += prev_status[(num + 3) % 5];
            prev_status[num % 5] += prev_status[(num + 4) % 5];
            prev_status[num % 5] %= mod;
        }
        return prev_status[n % 5];
    }
};
// @lc code=end
