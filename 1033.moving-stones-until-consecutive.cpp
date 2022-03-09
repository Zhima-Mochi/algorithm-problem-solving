/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        if (arr[0] + 2 < arr[1] && arr[1] + 2 < arr[2])
        {
            return {2, arr[2] - arr[0] - 2};
        }
        else if (arr[0] + 2 == arr[1] || arr[1] + 2 == arr[2])
        {
            return {1, arr[2] - arr[0] - 2};
        }
        else
        {
            return {arr[2] - arr[0] > 2 ? 1 : 0, arr[2] - arr[0] - 2};
        }
    }
};
// @lc code=end
