/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head==nullptr){
            return head;
        }
        auto cur=head;
        auto uniq_cur=cur;
        while(cur->next!=nullptr){
            auto next_cur=cur->next;
            if(uniq_cur->val==next_cur->val){
                cur=next_cur;
            }else{
                uniq_cur->next=next_cur;
                uniq_cur=next_cur;
                cur=next_cur;
            }
        }
        uniq_cur->next=nullptr;
        return head;
    }
};
// @lc code=end
