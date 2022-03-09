/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> st;
        int width = prices.size();
        for (int i = 0; i != width; ++i)
        {
            while (!st.empty() && prices[st.back()] >= prices[i])
            {
                prices[st.back()] -= prices[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return prices;
    }
};
// @lc code=end
