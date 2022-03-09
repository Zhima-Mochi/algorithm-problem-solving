/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        st.push(x);
        ++size;
        if (size == threshold)
        {
            stack<int> temp;
            while (ordered_stack.size())
            {
                temp.push(ordered_stack.top());
                ordered_stack.pop();
            }
            auto rest = size - temp.size();
            while (rest)
            {
                ordered_stack.push(st.top());
                st.pop();
                --rest;
            }
            st = stack<int>();
            while (temp.size())
            {
                ordered_stack.push(temp.top());
                temp.pop();
            }
            threshold *= 2;
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (ordered_stack.empty())
        {
            auto temp = st.top();
            st.pop();
            --size;
            return temp;
        }
        else
        {
            auto temp = ordered_stack.top();
            ordered_stack.pop();
            --size;
            if (size < threshold / 2)
            {
                threshold = max(2, threshold / 2);
            }
            return temp;
        }
    }

    /** Get the front element. */
    int peek()
    {
        if (ordered_stack.empty())
        {
            return st.top();
        }
        else
        {
            return ordered_stack.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return size == 0;
    }

private:
    stack<int> st;
    stack<int> ordered_stack;
    int threshold = 2;
    int size = 0;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
