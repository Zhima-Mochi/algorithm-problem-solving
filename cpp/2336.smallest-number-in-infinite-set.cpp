/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */
#include <set>
using namespace std;
// @lc code=start
class SmallestInfiniteSet
{
    set<int> s;
    int start = 1;

public:
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        s.insert(start++);
        int res = *s.begin();
        s.erase(res);
        return res;
    }

    void addBack(int num)
    {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
