/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void addNode(vector<int>& nums,TreeNode* root,int left,int right){
        if(right>=left){
            auto middle=left+(right-left)/2;
            auto new_node=new TreeNode(nums[middle]);
            if (root->val<nums[middle]){
                root->right=new_node;
            }else{
                root->left=new_node;
            }
            addNode(nums,new_node,left,middle-1);
            addNode(nums,new_node,middle+1,right);
        }else{
            return;
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        auto middle=left+(right-left)/2;
        auto head=new TreeNode(nums[middle]);
        addNode(nums,head,left,middle-1);
        addNode(nums,head,middle+1,right);
        return head;
    }
};
// @lc code=end

