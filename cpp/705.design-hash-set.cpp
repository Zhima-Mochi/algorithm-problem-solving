/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */
#include <vector>
using namespace std;
// @lc code=start
class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        if (key + 1 > v.size())
        {
            v.resize(key + 10);
        }
        v[key] = true;
    }

    void remove(int key)
    {
        if (key + 1 > v.size())
        {
            v.resize(key + 10);
        }
        v[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        if (key + 1 > v.size())
        {
            v.resize(key + 10);
        }
        return v[key];
    }

private:
    vector<bool> v = vector<bool>(100);
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
