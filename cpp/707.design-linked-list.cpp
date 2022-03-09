/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class DL
{
public:
    DL(int _val) : val(_val) {}
    DL(int _val, DL *_prev, DL *_next) : val(_val), prev(_prev), next(_next)
    {
    }
    int val;
    DL *prev, *next;
};
class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        len = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        auto res = get_pointer(index);
        if (res)
        {
            return res->val;
        }
        else
        {
            return -1;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        ++len;
        if (len == 1)
        {
            head = tail = new DL(val);
        }
        else
        {
            head = new DL(val, nullptr, head);
            head->next->prev = head;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        ++len;
        if (len == 1)
        {
            head = tail = new DL(val);
        }
        else
        {
            tail = new DL(val, tail, nullptr);
            tail->prev->next = tail;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > len)
        {
            return;
        }
        else if (index == len)
        {
            addAtTail(val);
            return;
        }
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        auto cur = get_pointer(index);
        cur->prev = new DL(val, cur->prev, cur);
        cur->prev->prev->next = cur->prev;
        ++len;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= len)
        {
            return;
        }
        else if (len == 1)
        {
            delete (head);
            head = tail = nullptr;
            len = 0;
            return;
        }
        auto cur = get_pointer(index);
        if (cur != head)
        {
            cur->prev->next = cur->next;
        }
        else
        {
            head = head->next;
        }
        if (cur != tail)
        {
            cur->next->prev = cur->prev;
        }
        else
        {
            tail = cur->prev;
        }
        delete (cur);
        --len;
    }

private:
    int len;
    DL *head;
    DL *tail;
    DL *get_pointer(int index)
    {
        if (index >= len)
        {
            return nullptr;
        }
        if (index < len / 2)
        {
            auto cur = head;
            while (index--)
            {
                cur = cur->next;
            }
            return cur;
        }
        else
        {
            auto cur = tail;
            index = len - index - 1;
            while (index--)
            {
                cur = cur->prev;
            }
            return cur;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end