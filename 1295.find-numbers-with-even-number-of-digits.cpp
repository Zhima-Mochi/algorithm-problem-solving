/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto res=0;
        for(auto &n:nums){
            if(n<=9){
                continue;
            }else if(n<=99){
                ++res;
            }else if(n<=999){
                continue;
            }else if(n<=9999){
                ++res;
            }else if(n<=99999){
                continue;
            }else{
                ++res;
            }     
        }
        return res;
    }
};
// @lc code=end

