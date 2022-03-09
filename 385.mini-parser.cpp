/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */
#include <vector>
#include <stack>
#include <string>s
using namespace std;
class NestedInteger
{
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        stack<NestedInteger> st_nest;
        st_nest.push(NestedInteger());
        int width = s.size();
        int pos = 0;
        while (pos < width)
        {
            if (s[pos] == '[')
            {
                st_nest.push(NestedInteger());
                ++pos;
            }
            else if (isdigit(s[pos]) || s[pos] == '-')
            {
                int next_pos = pos + 1;
                while (isdigit(s[next_pos]))
                {
                    ++next_pos;
                }
                st_nest.top().add(NestedInteger(stoi(s.substr(pos, next_pos - pos))));
                pos = next_pos;
            }
            else if (s[pos] == ']')
            {
                auto elem = st_nest.top();
                st_nest.pop();
                st_nest.top().add(elem);
                ++pos;
            }
            else
            {
                ++pos;
            }
        }
        return st_nest.top().getList()[0];
    }
};
// @lc code=end
