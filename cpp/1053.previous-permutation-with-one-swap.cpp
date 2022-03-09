/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {
        int w = arr.size();
        for (int i = w - 2; i >= 0; --i)
        {
            if (arr[i] > arr[i + 1])
            {
                int cand = i + 1;
                for (int j = i + 1; j < w && arr[j] < arr[i]; ++j)
                {
                    if (arr[cand] < arr[j])
                    {
                        cand = j;
                    }
                }
                swap(arr[i], arr[cand]);
                return arr;
            }
        }
        return arr;
    }
};
// @lc code=end
