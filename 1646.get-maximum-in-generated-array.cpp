/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> arr = vector<int>(101, -1);

public:
    int getMaximumGenerated(int n)
    {
        arr[0] = 0;
        arr[1] = 1;
        if (n <= 1)
        {
            return n;
        }
        for (int i = 0; i <= n; ++i)
        {
            helpler(i);
        }
        return *max_element(arr.begin(), arr.end());
    }
    int helpler(int n)
    {

        if (arr[n] == -1)
        {
            arr[n] = n % 2 == 0 ? helpler(n / 2) : helpler(n / 2) + helpler(n / 2 + 1);
        }
        return arr[n];
    }
};
// @lc code=end
