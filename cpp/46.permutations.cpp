/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    void heapPermutation(vector<vector<int>> &res,vector<int>& arr, int len)
    {
        if (len == 1)
        {
            res.push_back(arr);
            return;
        }

        for (int i = 0; i < len; i++)
        {
            heapPermutation(res,arr , len-1);

            if (len % 2 == 1)
                swap(arr[0], arr[len - 1]);
            else
                swap(arr[i], arr[len - 1]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        auto len = nums.size();
        heapPermutation(res,nums,len);
        return res;
    }
};
// @lc code=end
