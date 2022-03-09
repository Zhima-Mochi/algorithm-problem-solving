/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto cur_a=headA,cur_b=headB;
        while(cur_a!=cur_b){
            if(cur_a==nullptr){
                cur_a=headB;
            }else{
                cur_a=cur_a->next;
            }
            
            if(cur_b==nullptr){
                cur_b=headA;
            }else{
                cur_b=cur_b->next;
            }
        }
        return cur_a;
        // ListNode *res = nullptr;
        // auto pre_head = new ListNode(0);
        // auto len_a = 0, len_b = 0;
        // auto cur_b = headB;
        // while (cur_b != nullptr)
        // {
        //     len_b++;
        //     cur_b = cur_b->next;
        // }

        // pre_head->next = headA;
        // auto next_cur = headA, cur = pre_head;
        // while (next_cur != nullptr)
        // {
        //     len_a++;
        //     auto temp = next_cur->next;
        //     next_cur->next = cur;
        //     cur = next_cur;
        //     next_cur = temp;
        // }

        // auto len_combine = 0;
        // cur_b = headB;
        // while (cur_b != nullptr && cur_b != pre_head)
        // {
        //     len_combine++;
        //     cur_b = cur_b->next;
        // }
        // auto pos = ((len_a + len_b) - len_combine + 1) / 2;

        // if (pos == 1 && cur_b == pre_head)
        // {
        //     res = cur;
        // }
        // next_cur = cur->next;
        // cur->next = nullptr;
        // while (next_cur != pre_head)
        // {
        //     pos--;
        //     if (pos == 1 && cur_b == pre_head)
        //     {
        //         res = next_cur;
        //     }
        //     auto temp = next_cur->next;
        //     next_cur->next = cur;
        //     cur = next_cur;
        //     next_cur = temp;
        // }
        // return res;
    }
};
// @lc code=end
