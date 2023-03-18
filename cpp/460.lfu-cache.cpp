/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
#include <vector>
#include <unordered_map>
#include <map>
#include <deque>
using namespace std;
// @lc code=start
class LFUCache
{
    int _capacity;
    unordered_map<int, int> key_val, key_freq;
    map<int, deque<int>> records;

public:
    LFUCache(int capacity)
    {
        _capacity = capacity;
        key_val.clear();
        key_freq.clear();
        records.clear();
    }

    int get(int key)
    {
        if (key_val.count(key))
        {
            helper(key);
            return key_val[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (_capacity == 0)
        {
            return;
        }
        helper(key);
        key_val[key] = value;
    }

    void helper(int key)
    {
        if (!key_val.count(key))
        {
            if (key_val.size() == _capacity)
            {
                for (auto &[freq, record] : records)
                {
                    while (!record.empty() && key_freq[record.front()] != freq)
                    {
                        record.pop_front();
                    }
                    if (!record.empty())
                    {
                        auto should_remove = record.front();
                        record.pop_front();
                        key_val.erase(should_remove);
                        key_freq.erase(should_remove);
                        break;
                    }
                }
            }
        }
        key_freq[key] += 1;
        records[key_freq[key]].push_back(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
