/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int w = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq(w);
        iota(dq.begin(), dq.end(), 0);
        vector<int> res(w);
        for (int i = 0; i != w; ++i)
        {
            res[dq.front()] = deck[i];
            dq.pop_front();
            if (dq.empty())
            {
                break;
            }
            dq.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};
// @lc code=end
