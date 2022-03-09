/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(len(fruits)), s:O(1)
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int pick_type_1 = -1;
        int pick_type_2 = -1;
        int pick_1_last_idx = -1;
        int pick_2_last_idx = -1;
        int cnt = 0;
        int res = 0;
        for (int i = 0, w = fruits.size(); i != w; ++i)
        {
            if (pick_type_1 == fruits[i])
            {
                pick_1_last_idx = i;
                ++cnt;
            }
            else if (pick_type_2 == fruits[i])
            {
                pick_2_last_idx = i;
                ++cnt;
            }
            else if (pick_type_1 == -1)
            {
                pick_type_1 = fruits[i];
                pick_1_last_idx = i;
                ++cnt;
            }
            else if (pick_type_2 == -1)
            {
                pick_type_2 = fruits[i];
                pick_2_last_idx = i;
                ++cnt;
            }
            else
            {
                res = max(cnt, res);
                if (pick_1_last_idx < pick_2_last_idx)
                {
                    cnt = i - pick_1_last_idx;
                    pick_type_1 = fruits[i];
                    pick_1_last_idx = i;
                }
                else
                {
                    cnt = i - pick_2_last_idx;
                    pick_type_2 = fruits[i];
                    pick_2_last_idx = i;
                }
            }
        }
        return res = max(cnt, res);
    }
};
// @lc code=end
