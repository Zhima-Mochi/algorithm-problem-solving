/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

// @lc code=start
// t:O(1), s:O(n)
class node
{
public:
    node *prev = nullptr, *next = nullptr;
    int val;
    node(int val) : val(val) {}
};

class FrontMiddleBackQueue
{
    node *back, *middle, *root;
    int w = 0;
    int mid_pos = -1;

public:
    FrontMiddleBackQueue()
    {
        root = new node(0);
        back = middle = nullptr;
    }
    node *insert(node *nd, int val)
    {
        auto nd_next = nd->next;
        nd->next = new node(val);
        nd->next->prev = nd;
        if (nd_next)
        {
            nd->next->next = nd_next;
            nd_next->prev = nd->next;
        }
        w++;
        return nd->next;
    }
    node *erase(node *nd)
    {
        auto nd_prev = nd->prev;
        auto nd_next = nd->next;
        if (nd_prev)
        {
            nd_prev->next = nd_next;
        }
        if (nd_next)
        {
            nd_next->prev = nd_prev;
        }
        w--;
        return nd_prev;
    }
    void shift_middle()
    {
        if (w == 0)
        {
            return;
        }
        while (mid_pos > (w - 1) / 2)
        {
            middle = middle->prev;
            mid_pos--;
        }
        while (mid_pos < (w - 1) / 2)
        {
            middle = middle->next;
            mid_pos++;
        }
    }
    void pushFront(int val)
    {
        if (w == 0)
        {
            back = middle = insert(root, val);
            mid_pos = 0;
            return;
        }
        insert(root, val);
        mid_pos++;
        shift_middle();
    }

    void pushMiddle(int val)
    {
        if (w == 0)
        {
            back = middle = insert(root, val);
            mid_pos = 0;
            return;
        }
        if (w % 2 == 0)
        {
            middle = insert(middle, val);
            mid_pos++;
        }
        else
        {
            middle = insert(middle->prev, val);
        }
        shift_middle();
        if (back->next)
        {
            back = back->next;
        }
    }

    void pushBack(int val)
    {
        if (w == 0)
        {
            back = middle = insert(root, val);
            mid_pos = 0;
            return;
        }
        back = insert(back, val);
        shift_middle();
    }

    int popFront()
    {
        if (w == 0)
        {
            return -1;
        }
        int res = root->next->val;
        erase(root->next);
        mid_pos -= 1;
        shift_middle();
        return res;
    }

    int popMiddle()
    {
        if (w == 0)
        {
            return -1;
        }
        int res = middle->val;
        middle = erase(middle);
        mid_pos -= 1;
        shift_middle();
        return res;
    }

    int popBack()
    {
        if (w == 0)
        {
            return -1;
        }
        int res = back->val;
        back = erase(back);
        shift_middle();
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
