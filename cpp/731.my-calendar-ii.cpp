/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start

// Boundary Count
// T:O(N(logN+N))=O(N^2) S:O(N)
class MyCalendarTwo
{
    map<int, int> end_points;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        ++end_points[start];
        --end_points[end];
        int count = 0;
        for (auto &p : end_points)
        {
            count += p.second;
            if (count > 2)
            {
                --end_points[start];
                ++end_points[end];
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end