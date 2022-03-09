/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        vector<ListNode*>arr;
        auto cur=head;
        while(cur!=nullptr){
            arr.push_back(cur);
            cur=cur->next;
        }
        auto len =arr.size();
        if (len==0){
            return head;
        }
        k%=len;
        if(k==0){
            return head;
        }
        arr.back()->next=head;
        head=arr[len-k];
        arr[len-k-1]->next=nullptr;
        return head;
    }
};
// @lc code=end
