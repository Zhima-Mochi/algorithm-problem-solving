/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {

    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        queue<int> new_q;
        while(q.size()!=1){
            new_q.push(q.front());
            q.pop();
        }
        int res= q.front();
        q=new_q;
        return res;
    }

    /** Get the top element. */
    int top()
    {
        queue<int> new_q;
        while(q.size()!=1){
            new_q.push(q.front());
            q.pop();
        }
        int res= q.front();
        q=new_q;
        q.push(res);
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end