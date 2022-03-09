/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> vec(37);
        for (int i = 1; i != n + 1; ++i)
        {
            ++vec[helpler(i)];
        }
        int max_size = 0;
        int res = 0;
        for (auto v : vec)
        {
            if(v>max_size){
                res=1;
                max_size=v;
            }else if (v==max_size){
                ++res;
            }
        }
        return res;
    }
    int helpler(int num)
    {
        int res = 0;
        while (num)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};
// @lc code=end
