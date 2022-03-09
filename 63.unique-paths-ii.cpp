/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        auto width=obstacleGrid[0].size();
        vector<int> res(width,0);
        res[0]=1;
        auto cur=0;
        for(auto & vec : obstacleGrid){
            auto first_zero=false;
            for (int i=cur;i!=width;++i){
                if(vec[i]==1){
                    res[i]=0;
                }else if(!first_zero){
                    first_zero=true;
                    cur=i;
                }else{
                    res[i]+=res[i-1];
                }
            }
        }
        return res[width-1];
    }
};
// @lc code=end
