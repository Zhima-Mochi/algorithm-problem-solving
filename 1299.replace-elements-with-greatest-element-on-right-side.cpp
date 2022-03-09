/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int max_val = -1;
        for (auto i = arr.size() - 1; i != -1; --i)
        {
            max_val = max(max_val, exchange(arr[i], max_val));
        }
        return arr;
    }
};
// @lc code=end
