/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int w = strs.size();
        vector<int> strsGroup(w, 0);
        for (int i = 0; i != w; ++i)
        {
            strsGroup[i] = i;
        }
        function<int(int)> getGroup = [&](int n)
        {
            if (strsGroup[n] == n)
            {
                return n;
            }
            return strsGroup[n] = getGroup(strsGroup[n]);
        };

        for (int i = 0; i != w; ++i)
        {
            for (int j = i + 1; j != w; ++j)
            {
                int ig = getGroup(strsGroup[i]);
                int jg = getGroup(strsGroup[j]);
                if (ig == jg)
                {
                    continue;
                }
                if (isSimilar(i, j, strs))
                {
                    strsGroup[ig] = jg;
                }
            }
        }

        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (i == getGroup(strsGroup[i]))
            {
                res++;
            }
        }
        return res;
    }
    bool isSimilar(int i, int j, vector<string> &strs)
    {
        string a = strs[i];
        string b = strs[j];
        int w = a.size();
        int diff_cnt = 0;
        int val = 0;
        for (int i = 0; i != w; ++i)
        {
            if (a[i] != b[i])
            {
                diff_cnt++;
                if (diff_cnt > 2)
                {

                    return false;
                }
                val += a[i] - b[i];
            }
        }
        return val == 0;
    }
};
// @lc code=end
