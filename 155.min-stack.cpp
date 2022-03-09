/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
// @lc code=start
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int val)
    {
        v.push_back(val);
        if (v[min_index] > val)
        {
            min_index = v.size() - 1;
        }
    }

    void pop()
    {
        if (min_index == v.size() - 1)
        {
            v.pop_back();
            if (!v.empty())
            {
                min_index = 0;
                for (int i = 1; i != v.size(); i++)
                {
                    if (v[min_index] > v[i])
                    {
                        min_index = i;
                    }
                }
            }
        }
        else
        {
            v.pop_back();
        }
    }

    int top()
    {
        return v.back();
    }

    int getMin()
    {
        return v[min_index];
    }

private:
    vector<int> v;
    int min_index = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
