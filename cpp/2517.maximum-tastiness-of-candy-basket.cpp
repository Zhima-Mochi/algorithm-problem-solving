/*
 * @lc app=leetcode id=2517 lang=cpp
 *
 * [2517] Maximum Tastiness of Candy Basket
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)+nlog(diff)), s:O(log(n))
class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        auto last = unique(price.begin(), price.end());
        price.erase(last, price.end());

        if (price.size() < k)
        {
            return 0;
        }

        int left = 0, right = price.back() - price.front();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int prev = -price.back();
            int cnt = 0;
            for (auto p : price)
            {
                if (p - prev > mid)
                {
                    prev = p;
                    cnt++;
                }
                if (cnt >= k)
                {
                    break;
                }
            }
            if (cnt >= k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
