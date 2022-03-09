/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        int width = deck.size();
        deck.push_back(-1);
        int cur = 0;
        int x = 0;
        while (cur != width)
        {
            int left = cur, right = width;
            while (left < right)
            {
                int middle = left + (right - left) / 2;
                if (deck[middle] != deck[cur])
                {
                    right = middle;
                }
                else
                {
                    left = middle + 1;
                }
            }
            if (x == 0)
            {
                x = left - cur;
            }
            else
            {
                x = gcd(x, left - cur);
            }
            if (x <= 1)
            {
                return false;
            }
            cur = left;
        }
        return true;
    }
};
// @lc code=end
