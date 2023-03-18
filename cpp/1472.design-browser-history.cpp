/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(1), s:O(n)
class BrowserHistory
{
    vector<string> history;
    int cursor = 0;

public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
    }

    void visit(string url)
    {
        cursor += 1;
        history.resize(cursor);
        history.push_back(url);
    }

    string back(int steps)
    {
        if (steps > cursor)
        {
            cursor = 0;
        }
        else
        {
            cursor -= steps;
        }
        return history[cursor];
    }

    string forward(int steps)
    {
        if (steps > history.size() - cursor - 1)
        {
            cursor = history.size() - 1;
        }
        else
        {
            cursor += steps;
        }
        return history[cursor];
    };
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
