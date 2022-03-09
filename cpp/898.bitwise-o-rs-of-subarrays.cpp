/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> res;
        int w = arr.size();
        for (int i = 0; i != w; ++i)
        {
            res.insert(arr[i]);
            for (int j = i - 1; j != -1; --j)
            {
                if (arr[j] == (arr[j] | arr[i]))
                {
                    break;
                }
                arr[j] |= arr[i];
                res.insert(arr[j]);
            }
        }
        return res.size();
    }
};
// @lc code=end
