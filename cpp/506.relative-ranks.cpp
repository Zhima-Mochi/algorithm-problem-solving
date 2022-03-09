/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    string binary_search(vector<int> &sort_score, int score)
    {
        int left = 0, right = sort_score.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (sort_score[mid] > score)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (left == 0)
        {
            return "Gold Medal";
        }
        else if (left == 1)
        {
            return "Silver Medal";
        }
        else if (left == 2)
        {
            return "Bronze Medal";
        }
        else
        {
            return to_string(left + 1);
        }
    }

public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        auto sort_score = score;
        sort(sort_score.begin(), sort_score.end(), greater<int>());
        vector<string> res;
        for (auto &s : score)
        {
            res.push_back(binary_search(sort_score, s));
        }
        return res;
    }
};
// @lc code=end
