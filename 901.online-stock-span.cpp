/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */
#include <vector>
using namespace std;
// @lc code=start
class StockSpanner
{
    vector<int> arr;
    vector<int> record;

public:
    StockSpanner()
    {
        arr.reserve(10000);
        record.reserve(10000);
    }

    int next(int price)
    {
        record.push_back(get_span(arr.size() - 1, price));
        arr.push_back(price);
        return record.back();
    }
    int get_span(int idx, int val)
    {
        if (idx < 0 || arr[idx] > val)
        {
            return 1;
        }
        else
        {
            int v = record[idx];
            record.pop_back();
            arr.pop_back();
            return v + get_span(idx - 1, val);
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
