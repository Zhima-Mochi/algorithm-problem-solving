/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        
        vector<int> prev={0,1,1,2};
        if(n<=3){
            return prev[n];
        }
        n-=3;
        auto cur = 0;
        while (n--)
        {
            swap(prev[cur], prev.back());
            prev.back() = 0;
            for (int j = 0; j != 3; ++j)
            {
                prev.back() += prev[j];
            }
            ++cur;
            cur %= 3;
        }
        return prev.back();
    }
};
// @lc code=end
