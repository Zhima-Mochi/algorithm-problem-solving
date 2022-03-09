/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_sum=0;
        int low_price=prices[0];
        for(auto &p:prices){
            if(p>low_price){
                max_sum=max(max_sum,p-low_price);
            }else if(p<low_price){
                low_price=p;
            }
        }
        return max_sum; 
    }
};
// @lc code=end

