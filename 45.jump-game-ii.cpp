/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{

public:
    int jump(vector<int> &nums)
    {
        auto cur_index = nums.size() - 1;
        if (cur_index <=1)
        {
            return cur_index;
        }
        vector<int> jump_map;

        for (int i = 0; i != cur_index; i++)
        {
            auto maximum_jump_to = i + nums[i];
            auto jump_map_len = jump_map.size();
            if (jump_map_len == 0 || maximum_jump_to > jump_map.back())
            {

                if (jump_map_len >= 2)
                {
                    if (jump_map[jump_map_len - 2] >= i)
                    {
                        jump_map.pop_back();
                    }
                }
                jump_map.push_back(maximum_jump_to);
            }
            if (cur_index <= maximum_jump_to)
            {
                break;
            }
        }
        return jump_map.size();
    }
};
// @lc code=end
// int jump(vector<int> &nums)
//     {
//         if(nums.size()<=2){
//             return nums.size()-1;
//         }
//         int jump_times=0;
//         int cur_end=0,cur=0;
//         while(cur_end<nums.size()-1){
//             auto maximum_jump_pos=cur+nums[cur];
//             for(;cur<=cur_end;cur++){
//                 maximum_jump_pos=max(maximum_jump_pos,cur+nums[cur]);
//             }
//             cur_end=maximum_jump_pos;
//             jump_times++;
//         }
//         return jump_times;
//     }