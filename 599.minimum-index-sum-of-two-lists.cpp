/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int rank_sum = 2000;
        int len1 = list1.size(), len2 = list2.size();
        vector<string> res;
        unordered_map<string, short> umap;
        for (int i = 0; i != len1; ++i)
        {
            umap[list1[i]] = i;
        }
        for (int j = 0; j != len2; ++j)
        {
            if (umap.count(list2[j]))
            {
                if (j + umap[list2[j]] < rank_sum)
                {
                    rank_sum = j + umap[list2[j]];
                    res = vector<string>{list2[j]};
                }
                else if (j + umap[list2[j]] == rank_sum)
                {
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
