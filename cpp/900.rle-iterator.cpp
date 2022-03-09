/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */
#include <vector>
using namespace std;
// @lc code=start
class RLEIterator
{
    vector<int> ed;
    int pt = 0;
    int w;

public:
    RLEIterator(vector<int> &encoding)
    {
        ed = encoding;
        w = encoding.size();
    }

    int next(int n)
    {
        if (pt == w)
        {
            return -1;
        }
        else if (ed[pt] >= n)
        {
            ed[pt] -= n;
            return ed[pt + 1];
        }
        else
        {
            n -= ed[pt];
            pt += 2;
            return next(n);
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
// @lc code=end
