/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class SegmentTreeNode
{
public:
    SegmentTreeNode(int _start, int _end) : start(_start), end(_end)
    {
    }
    int start, end;
    SegmentTreeNode *left, *right;
    int sum;
    static void buildTree(vector<int> &nums, SegmentTreeNode *root)
    {
        if (root->start == root->end)
        {
            root->sum = nums[root->start];
            return;
        }
        auto mid = root->start + (root->end - root->start) / 2;
        root->left = new SegmentTreeNode(root->start, mid);
        root->right = new SegmentTreeNode(mid + 1, root->end);
        buildTree(nums, root->left);
        buildTree(nums, root->right);
        root->sum = root->left->sum + root->right->sum;
    }
    static void updateTree(SegmentTreeNode *root, int &index, int &val)
    {
        if (root->start == root->end)
        {
            root->sum = val;
            return;
        }
        auto mid = root->start + (root->end - root->start) / 2;
        if (index <= mid)
        {
            updateTree(root->left, index, val);
        }
        else
        {
            updateTree(root->right, index, val);
        }
        root->sum = root->left->sum + root->right->sum;
    }
    static int findSum(SegmentTreeNode *root, int start, int end)
    {
        
        if (root->start == start && root->end == end)
        {
            return root->sum;
        }
        auto mid = root->start + (root->end - root->start) / 2;
        if (mid >= end)
        {
            return findSum(root->left, start, end);
        }
        else if (mid < start)
        {
            return findSum(root->right, start, end);
        }
        else
        {
            return findSum(root->left, start, mid) + findSum(root->right, mid + 1, end);
        }
    }
};
class NumArray
{

public:
    NumArray(vector<int> &nums) : root(new SegmentTreeNode(0, nums.size() - 1))
    {
        SegmentTreeNode::buildTree(nums, root);
    }

    void update(int index, int val)
    {
        SegmentTreeNode::updateTree(root, index, val);
    }

    int sumRange(int left, int right)
    {
        return SegmentTreeNode::findSum(root, left, right);
    }

private:
    SegmentTreeNode *root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
//["NumArray","update","sumRange","sumRange","update","sumRange"] \n[[[9,-8]],[0,3],[1,1],[0,1],[1,-3],[0,1]]
