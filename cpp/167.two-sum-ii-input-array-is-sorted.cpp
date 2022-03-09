/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            auto sum = numbers[right] + numbers[left];
            if (sum == target)
            {
                return vector<int>{left+1, right+1};
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return vector<int>();
        // unordered_map<int,int> pos_map;
        // auto len = numbers.size();
        // for(int i=0;i!=len;i++){
        //     if(pos_map.find(numbers[i])!=pos_map.end()){
        //         return vector<int>{pos_map[numbers[i]],i+1};
        //     }else{
        //         pos_map[target-numbers[i]]=i+1;
        //     }
        // }
        // return vector<int>();
    }
};
// @lc code=end
