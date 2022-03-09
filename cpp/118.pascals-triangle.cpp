/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    void generatePascal(vector<vector<int>> &res, int numRows)
    {
        if (numRows == 0)
        {
            return;
        }
        if (res.empty())
        {
            res.push_back(vector<int>{1});
            generatePascal(res, numRows - 1);
        }
        else
        {
            auto vec = res.back();
            vec.push_back(1);
            auto len = vec.size();
            auto half_len = (len + 1) / 2;
            for (int i = 1; i != half_len; ++i)
            {
                vec[i] += vec[len - 1 - i];
                vec[len - 1 - i] = vec[i];
            }
            res.push_back(vec);
            generatePascal(res, numRows - 1);
        }
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        //generatePascal(res,numRows);
        if (numRows >= 1)
        {
            res.push_back(vector<int>{1});
            numRows -= 1;
        }
        for (int i = 1; i <= numRows; ++i)
        {
            auto vec = res.back();
            vec.push_back(1);
            auto len = vec.size();
            auto half_len = (len + 1) / 2;
            for (int i = 1; i != half_len; ++i)
            {
                vec[i] += vec[len - 1 - i];
                vec[len - 1 - i] = vec[i];
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
