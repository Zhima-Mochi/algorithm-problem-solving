/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_sum=0;
        int low_price=prices[0];
        for(auto &p : prices){
            if(p>low_price){
                total_sum+=p-low_price;
                low_price=p;
            }else if(p<low_price){
                low_price=p;
            }
        }
        return total_sum;
    }
};
// @lc code=end

