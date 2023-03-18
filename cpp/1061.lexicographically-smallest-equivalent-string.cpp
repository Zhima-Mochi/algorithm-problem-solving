/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> GroupNum;
    int findGroup(int alpha)
    {
        if(GroupNum[alpha]!=alpha){
            GroupNum[alpha]=findGroup(GroupNum[alpha]);
        }
        return GroupNum[alpha];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        GroupNum = vector<int>(26);
        for (int i = 1; i != 26; ++i)
        {
            GroupNum[i] = i;
        }
        int w = s1.size();
        for (int i = 0; i != w; ++i)
        {
            int word1Ind = s1[i] - 'a';
            int word2Ind = s2[i] - 'a';
            int left = findGroup(word1Ind);
            int right = findGroup(word2Ind);
            if (right > left)
            {
                GroupNum[right] = GroupNum[left];
            }
            else
            {
                GroupNum[left] = GroupNum[right];
            }
        }
         for (int i = 1; i != 26; ++i)
        {
            GroupNum[i] = findGroup(i);
        }
        for (auto &c : baseStr)
        {
            c = 'a' + GroupNum[c - 'a'];
        }
        return baseStr;
    }
};
// @lc code=end

