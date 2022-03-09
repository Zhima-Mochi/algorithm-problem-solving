/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int last_term_candy = (-1 + sqrt(1 + 4 * static_cast<long>(candies * 2))) / 2; //(-b+-(b^2-4ac)^0.5)/2
        int rest_candy = candies - (1 + last_term_candy) * last_term_candy / 2;
        vector<int> res;
        res.reserve(num_people);
        for (int i = 1, end = min(num_people, last_term_candy); i <= end; ++i)
        {
            int height = (last_term_candy - i) / num_people + 1;
            int required_candy = (i + (i + num_people * (height - 1))) * height / 2;
            res.push_back(required_candy);
        }
        res.resize(num_people);
        res[last_term_candy % num_people] += rest_candy;
        return res;
    }
};
// @lc code=end
