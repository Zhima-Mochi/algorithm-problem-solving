/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res={1};
        for (int i = 1; i <= rowIndex; ++i)
        {
            auto & vec = res;
            vec.push_back(1);
            auto len = vec.size();
            auto half_len = (len + 1) / 2;
            for (int i = 1; i != half_len; ++i)
            {
                vec[i] += vec[len - 1 - i];
                vec[len - 1 - i] = vec[i];
            }
        }
        return res;
    }
};
// @lc code=end

