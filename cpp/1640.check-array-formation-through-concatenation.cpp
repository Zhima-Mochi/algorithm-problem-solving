/*
 * @lc app=leetcode id=1640 lang=cpp
 *
 * [1640] Check Array Formation Through Concatenation
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, int> index_map;

public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {

        for (int i = 0, width = pieces.size(); i != width; ++i)
        {
            index_map[pieces[i][0]] = i;
        }
        int pos = 0;
        int width = arr.size();
        while (pos != width)
        {
            if (index_map.count(arr[pos]))
            {
                for (auto n : pieces[index_map[arr[pos]]])
                {
                    if (pos != width && n == arr[pos])
                    {
                        ++pos;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
