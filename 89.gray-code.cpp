/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res={0,1};
        auto count=1;
        while(count!=n){
            auto len=res.size();
            auto base=(1<<count);
            for(int i=0;i!=len;i++){
                res.push_back(res[len-1-i]+base);
            }
            count++;
        }
        return res;
    }
};
// @lc code=end

