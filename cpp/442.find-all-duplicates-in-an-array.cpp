/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len=nums.size();
        vector<int> res;
        for(int i=0;i!=len;++i){
            int pos=abs(nums[i])-1;
            if(nums[pos]>0){
                nums[pos]*=-1;
            }else{
                res.push_back(pos+1);
            }
        }
        return res;
    }
};
// @lc code=end

