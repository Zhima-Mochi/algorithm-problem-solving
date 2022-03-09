/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include <vector>
#include <unordered_set>
#include <set>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution
{
    void permute(set<vector<int>> &res,vector<int>& arr, int len)
    {
        if (len == 1)
        {
            res.insert(arr);
            return;
        }

        for (int i = 0; i < len; i++)
        {
            permute(res,arr , len-1);

            if (len % 2 == 1)
                swap(arr[0], arr[len - 1]);
            else
                swap(arr[i], arr[len - 1]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        set<vector<int>> collection;
        permute(collection, nums, nums.size());
        for(auto & elem: collection){
            res.push_back(elem);
        }
        return res;
    }
};
// @lc code=end
