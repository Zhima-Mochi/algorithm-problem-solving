/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> freq(201, 0);
        for (auto n : nums)
        {
            ++freq[n + 100];
        }
        sort(nums.begin(), nums.end(), [&freq](int &l, int &r)
             { if(freq[l + 100] < freq[r + 100]){
                 return true;
             }else if(freq[l + 100] == freq[r + 100]){
                 return l>r;
             }else{
                 return false;
             } });
        return nums;
    }
};
// @lc code=end
