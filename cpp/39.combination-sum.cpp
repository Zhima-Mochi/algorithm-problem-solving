/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
    void findCollection(vector<vector<int>> &res,vector<int>& candidates,int start_index,vector<int>&collection,int target){
        if (target==0){
            res.push_back(collection);
            return;
        }else if(collection.size()==150){
            return;
        }
        int len=candidates.size();
        for(;start_index!=len;start_index++){
            if(candidates[start_index]<=target){
                //auto new_collection=collection;
                //new_collection.push_back(candidates[start_index]);
                collection.push_back(candidates[start_index]);
                findCollection(res,candidates,start_index,collection,target-candidates[start_index]);
                collection.pop_back();
            }else{
                break;
            }
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> init;
        findCollection(res,candidates,0,init,target);
        return res;
    }
};
// @lc code=end

