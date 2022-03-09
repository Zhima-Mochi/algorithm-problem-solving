/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(auto & a: columnTitle){
            res*=26;
            res+=(a-'A'+1);
        }
        return res;
    }
};
// @lc code=end

