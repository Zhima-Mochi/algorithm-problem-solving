/*
 * @lc app=leetcode id=2034 lang=cpp
 *
 * [2034] Stock Price Fluctuation 
 */
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
// @lc code=start
class StockPrice
{
    int min_price = INT_MAX;
    int max_price = INT_MIN;
    int current_time;
    int current_price;
    unordered_map<int, int> record;
    multiset<int> prices;

public:
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        if (current_time <= timestamp)
        {
            current_time = timestamp;
            current_price = price;
        }
        if (record.count(timestamp))
        {
            auto p = prices.find(record[timestamp]);
            prices.erase(p);
        }
        record[timestamp] = price;
        prices.insert(price);
    }

    int current()
    {
        return current_price;
    }

    int maximum()
    {
        return *prev(prices.end(), 1);
    }

    int minimum()
    {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end
