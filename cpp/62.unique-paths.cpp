/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int &m, int &n) {
        int max,min;
        long res=1;
        if(m>n){
            max=m;
            min=n;
        }else{
            max=n;
            min=m;
        }
        
        for(int cur=max+min-2;cur!=max-1;cur--){
            res*=cur;
        }
        for(int cur=min-1;cur!=0;cur--){
            res/=cur;
        }
        return res;

    }
};
// @lc code=end

