/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */
#include <vector>
using namespace std;
// @lc code=start
class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        if (v[key % 100])
        {
            for (auto &pair : *v[key % 100])
            {
                if (pair.first == key)
                {
                    pair.second = value;
                    return;
                }
            }
            (*v[key % 100]).push_back({key, value});
        }
        else
        {
            v[key % 100] = new vector<pair<int, int>>(vector<pair<int, int>>{{key, value}});
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        if (v[key % 100])
        {
            for (auto &pair : *v[key % 100])
            {
                if (pair.first == key)
                {
                    return pair.second;
                }
            }
            return -1;
        }
        else
        {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        if (v[key % 100])
        {
            int count = 0;
            for (auto &pair : *v[key % 100])
            {
                if (pair.first == key)
                {
                    (*v[key % 100]).erase((*v[key % 100]).begin() + count);
                    return;
                }
                ++count;
            }
        }
        else
        {
            return;
        }
    }

private:
    vector<vector<pair<int, int>> *> v = vector<vector<pair<int, int>> *>(100, nullptr);
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
