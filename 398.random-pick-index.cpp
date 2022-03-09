/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    Solution(vector<int> &nums) : vec(nums)
    {
        len = vec.size();
    }

    int pick(int target)
    {
        int count = 0;
        int res = 0;
        for (int i = 0; i != len; ++i)
        {
            if (vec[i] != target)
            {
                continue;
            }
            else
            {
                ++count;
                if (rand() % count == 0)
                {
                    res = i;
                }
            }
        }
        return res;
    }
    vector<int> vec;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

// class Solution
// {
// public:
//     Solution(vector<int> &nums)
//     {
//         for (auto iter = nums.begin(), iterBegin = nums.begin(), iterEnd = nums.end(); iter != iterEnd; ++iter)
//         {
//             index_map[*iter].push_back(iter - iterBegin);
//         }
//     }

//     int pick(int target)
//     {
//         return index_map[target][rand() % index_map[target].size()];
//     }
//     unordered_map<int, vector<short>> index_map;
// };