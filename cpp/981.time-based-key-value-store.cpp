/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> key_time_value;

public:
    TimeMap()
    {
    }
    // t:O(1)
    void set(string key, string value, int timestamp)
    {
        key_time_value[key].push_back({timestamp, value});
    }
    // t:O(log(n))
    string get(string key, int timestamp)
    {
        if (!key_time_value.count(key))
        {
            return "";
        }
        auto &time_value = key_time_value[key];
        auto res = upper_bound(time_value.begin(), time_value.end(), pair<int, string>{timestamp, {127}});
        if (res == key_time_value[key].begin())
        {
            return "";
        }
        else
        {
            return prev(res)->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
