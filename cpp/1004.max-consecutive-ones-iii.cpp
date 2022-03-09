/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
#include <queue>
#include <deque>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left=0,right=0;
        auto len=nums.size();
        for(;right!=len;right++){
            if(nums[right]==0){
                k--;
            }
            if(k<0 && nums[left++]==0){
                k++;
            }
           
        }
         return right-left;

        // int coin = k;
        // int accum_sum = 0;
        // int max_sum = 0;
        // int count = 0;
        // queue<int> coin_consume;
        // queue<int> one_queue;
        // auto end_iter = nums.end();
        // auto index_iter = find(nums.begin(), end_iter, 1);

        // while (index_iter != end_iter)
        // {
        //     max_sum = max(max_sum, accum_sum);

        //     auto zero_iter = find(index_iter, end_iter, 0);
        //     int one_amount = zero_iter - index_iter;
        //     one_queue.push(one_amount);
        //     accum_sum += one_amount;
        //     index_iter = find(zero_iter, end_iter, 1);
        //     int zero_amount = index_iter - zero_iter;

        //     if (coin >= zero_amount)
        //     {
        //         if (zero_amount == 0)
        //         {
        //             break;
        //         }
        //         coin_consume.push(zero_amount);
        //         coin -= zero_amount;
        //     }
        //     else if (zero_amount > k)
        //     {
        //         max_sum = max(max_sum, accum_sum);
        //         accum_sum = 0;
        //         coin = k;
        //         coin_consume = queue<int>();
        //         one_queue = queue<int>();
        //     }
        //     else
        //     {
        //         max_sum = max(max_sum, accum_sum);
        //         while (coin < zero_amount)
        //         {
        //             coin += coin_consume.front();
        //             coin_consume.pop();
        //             accum_sum -= one_queue.front();
        //             one_queue.pop();
        //         }
        //         coin_consume.push(zero_amount);
        //         coin -= zero_amount;
        //     }
        // }
        // max_sum = max(max_sum, accum_sum);
        // return min(max_sum + k, static_cast<int>(nums.size()));
    }
};
// @lc code=end
