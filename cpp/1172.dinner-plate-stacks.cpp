/*
 * @lc app=leetcode id=1172 lang=cpp
 *
 * [1172] Dinner Plate Stacks
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t: O(logn), s: O(n)
class DinnerPlates
{
    vector<vector<int>> stks;
    priority_queue<int, vector<int>, greater<int>> q;
    int cap;

public:
    DinnerPlates(int capacity)
    {
        cap = capacity;
        stks = vector<vector<int>>();
        q = priority_queue<int, vector<int>, greater<int>>();
    }

    void push(int val)
    {
        while (true)
        {
            if (q.empty())
            {
                if (!stks.empty()&& stks.back().size() < cap)
                {
                    stks.back().push_back(val);
                    if (stks.back().size() < cap)
                    {
                        q.push(stks.size() - 1);
                    }
                    return;
                }
                stks.push_back(vector<int>{val});
                if (stks.back().size() < cap)
                {
                    q.push(stks.size() - 1);
                }
                return;
            }
            int pos = q.top();
            q.pop();
            if (pos >= stks.size())
            {
                continue;
            }
            if (stks[pos].size() == cap)
            {
                continue;
            }
            stks[pos].push_back(val);
            if (stks[pos].size() < cap)
            {
                q.push(pos);
            }
            break;
        }
    }

    int pop()
    {
        if (stks.empty())
        {
            return -1;
        }
        while (stks.back().empty())
        {
            stks.pop_back();
        }
        int res = stks.back().back();
        stks.back().pop_back();
        while (!stks.empty() && stks.back().empty())
        {
            stks.pop_back();
        }
        return res;
    }

    int popAtStack(int index)
    {
        if (index >= stks.size())
        {
            return -1;
        }
        if (stks[index].empty())
        {
            return -1;
        }
        int res = stks[index].back();
        stks[index].pop_back();
        q.push(index);
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end
