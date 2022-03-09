/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        int pos = 0;
        while ((pos = s.find_first_not_of(" ", pos)) != -1)
        {
            ++count;
            pos=s.find_first_of(" ", pos+1);
            if(pos==-1){
                break;
            }
        }
        return count;
        // int count = 0;
        // int len = s.size();
        // if (len == 0)
        // {
        //     return 0;
        // }
        // int start = 0;
        // int end = len - 1;
        // while (start != end && s[start] == ' ')
        // {
        //     ++start;
        // }
        // while (end != start && s[end] == ' ')
        // {
        //     --end;
        // }
        // if (start == end)
        // {
        //     return s[start]!=' ';
        // }
        // for (int i = start; i != end;)
        // {
        //     if (s[i] == ' ')
        //     {
        //         ++count;
        //         ++i;
        //         while (i != end && s[i] == ' ')
        //         {
        //             ++i;
        //         }
        //     }
        //     else
        //     {
        //         ++i;
        //     }
        // }
        // return count + 1;
    }
};
// @lc code=end
