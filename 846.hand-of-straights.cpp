/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
// t:O(len(hand)*log(len(hand))) s:O(groupSize)
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (groupSize == 1)
        {
            return true;
        }
        sort(hand.begin(), hand.end());

        hand.push_back(INT_MAX);

        queue<int> cnt;
        int w = hand.size();
        int num = 1;
        int b = 0;
        for (int i = 1; i < w; ++i)
        {
            if (hand[i] != hand[i - 1])
            {
                if (cnt.size() == groupSize)
                {
                    b = cnt.front();
                    while (!cnt.empty() && cnt.front() == b)
                    {
                        cnt.pop();
                    }
                }
                if (!cnt.empty() && cnt.back() > b + num)
                {
                    return false;
                }
                cnt.push(num + b);
                num = 1;

                if (hand[i] > hand[i - 1] + 1)
                {
                    if (cnt.size() < groupSize)
                    {
                        return false;
                    }

                    b = cnt.front();
                    while (!cnt.empty())
                    {
                        if (cnt.front() != b)
                        {
                            return false;
                        }
                        cnt.pop();
                    }
                    b = 0;
                }
            }
            else
            {
                ++num;
            }
        }
        return true;
    }
};
// @lc code=end
