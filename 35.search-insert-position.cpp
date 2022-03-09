/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto left=0;
        auto right=nums.size()-1;
        if(target<=nums[left]){
            return 0;
        }else if(target==nums[right]){
            return right;
        }else if (target >nums[right]){
            return right+1;
        }
        while(right-left!=1){
            auto middle=left+(right-left)/2;
            if (nums[middle]==target){
                return middle;
            }else if(nums[middle]<target){
                left=middle;
            }else{
                right=middle;
            }
        }
        return right;
    }
};
// @lc code=end

