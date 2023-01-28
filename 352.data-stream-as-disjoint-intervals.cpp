/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class SummaryRanges
{
    map<int, int> mp;

public:
    SummaryRanges()
    {
        mp.clear();
    }

    void addNum(int value)
    {
        auto after = mp.upper_bound(value);
        if (after == mp.begin())
        {
            if ((*after).first - 1 == value)
            {
                mp[value] = (*after).second;
                mp.erase(after);
            }
            else
            {
                mp[value] = value;
            }
            return;
        }
        auto before = prev(after);
        if (after != mp.end())
        {
            if ((*before).second + 1 == value && (*after).first - 1 == value)
            {
                (*before).second = (*after).second;
                mp.erase(after);
            }
            else if ((*before).second + 1 == value)
            {
                (*before).second = value;
            }
            else if ((*after).first - 1 == value)
            {
                mp[value] = (*after).second;
                mp.erase(after);
            }
            else if ((*before).second < value)
            {
                mp[value] = value;
            }
        }
        else if ((*before).second + 1 == value)
        {
            (*before).second = value;
        }
        else if ((*before).second < value)
        {
            mp[value] = value;
        }
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> res;
        auto cur = mp.begin();
        while (cur != mp.end())
        {
            res.push_back({cur->first, cur->second});
            cur = next(cur);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
