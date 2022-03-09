/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto init_head = new ListNode(0, head);
        auto div_length = 1;

        while (true)
        {
            auto pre_tail = init_head;
            auto first_node = pre_tail->next;
            ListNode *first_node_tail = nullptr;
            ListNode *second_node_tail = nullptr;
            auto second_node = split_node(first_node, div_length, &first_node_tail);
            if (second_node == nullptr)
            {
                break;
            }
            auto next_first = split_node(second_node, div_length, &second_node_tail);
            mergeSort(first_node, second_node, &pre_tail, first_node_tail, second_node_tail);

            while (next_first)
            {
                first_node = next_first;
                first_node_tail = nullptr;
                second_node_tail = nullptr;
                second_node = split_node(first_node, div_length, &first_node_tail);
                if (second_node == nullptr)
                {
                    pre_tail->next = first_node;
                    break;
                }
                next_first = split_node(second_node, div_length, &second_node_tail);
                mergeSort(first_node, second_node, &pre_tail, first_node_tail, second_node_tail);
            }
            div_length *= 2;
        }

        return init_head->next;
    }
    void mergeSort(ListNode *first_node, ListNode *second_node, ListNode **pre_tail, ListNode *first_node_tail, ListNode *second_node_tail)
    {
        auto cur = *pre_tail;
        while (first_node && second_node)
        {
            if (first_node->val <= second_node->val)
            {
                cur->next = first_node;
                first_node = first_node->next;
            }
            else
            {
                cur->next = second_node;
                second_node = second_node->next;
            }
            cur = cur->next;
        }
        if (first_node)
        {
            cur->next = first_node;
            *pre_tail = first_node_tail;
        }
        else
        {
            cur->next = second_node;
            *pre_tail = second_node_tail;
        }
    }
    ListNode *split_node(ListNode *start, int n, ListNode **pre_tail)
    {
        while (start->next && --n)
        {
            start = start->next;
        }
        if (*pre_tail == nullptr || (*pre_tail)->val <= start->val)
        {
            *pre_tail = start;
        }
        auto res = start->next;
        start->next = nullptr;
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         if (head == nullptr)
//         {
//             return nullptr;
//         }
//         auto init_head = new ListNode(0, head);
//         auto last = head;
//         while (last->next)
//         {
//             last = last->next;
//         }
//         quickSort(head, last, init_head);

//         return init_head->next;
//     }
//     void quickSort(ListNode *first, ListNode *last, ListNode *pre_tail)
//     {

//         if (first == last)
//         {
//             return;
//         }
//         auto pivot = first, fast = first;
//         while (fast->next != last && (fast = fast->next->next) != last)
//         {
//             pivot = pivot->next;
//         }
//         if (pivot->val < min(first->val, last->val))
//         {
//             pivot = first->val > last->val ? last : first;
//         }
//         else if (pivot->val > max(first->val, last->val))
//         {
//             pivot = first->val < last->val ? last : first;
//         }

//         auto next_head = last->next;
//         last->next = nullptr;

//         auto right = pivot->next, right_pivot_cur = pivot;

//         pre_tail->next = first;
//         auto cur = pre_tail;

//         while (cur->next != pivot)
//         {
//             if (cur->next->val > pivot->val)
//             {
//                 right_pivot_cur->next = cur->next;
//                 right_pivot_cur = right_pivot_cur->next;
//                 cur->next = right_pivot_cur->next;
//             }
//             else
//             {
//                 cur = cur->next;
//             }
//         }

//         while (right)
//         {
//             if (right->val <= pivot->val)
//             {
//                 cur->next = right;
//                 cur = cur->next;
//                 right = right->next;
//             }
//             else
//             {
//                 right_pivot_cur->next = right;
//                 right_pivot_cur = right;
//                 right = right->next;
//             }
//         }
//         right_pivot_cur->next = next_head;
//         cur->next = pivot;
//         if (pivot != right_pivot_cur)
//         {
//             quickSort(pivot->next, right_pivot_cur, pivot);
//         }
//         if (pre_tail != cur)
//         {
//             quickSort(pre_tail->next, cur, pre_tail);
//         }
//     }
// };