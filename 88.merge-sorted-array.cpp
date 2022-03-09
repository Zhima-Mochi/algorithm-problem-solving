/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        auto index_1=m-1,index_2=n-1;
        auto index_1_tail=m+n-1;
        while(index_1!=-1&&index_2!=-1){
            if(nums1[index_1]<nums2[index_2]){
                nums1[index_1_tail]=nums2[index_2];
                index_2--;
                index_1_tail--;
            }else{
                nums1[index_1_tail]=nums1[index_1];
                index_1--;
                index_1_tail--;
            }
        }
        while(index_2!=-1){
            nums1[index_2]=nums2[index_2];
            index_2--;
        }
    }
};
// @lc code=end

