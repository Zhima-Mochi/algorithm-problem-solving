/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // auto width = s.size();
        // unordered_map<char, int> mp_s, mp_t;
        // for (int i = 0; i != width; ++i)
        // {
        //     if (mp_s[s[i]] != mp_t[t[i]])
        //     {
        //         return false;
        //     }
        //     mp_s[s[i]] = i + 1;
        //     mp_t[t[i]] = i + 1;
        // }
        // return true;
        // auto width = s.size();
        // unordered_map<char, char> mp_s,mp_t;
        // for (int i = 0; i != width; ++i)
        // {
        //     if(mp_s.find(s[i])==mp_s.end()){
        //         mp_s.insert(pair<char,char>{s[i],t[i]});
        //     }else if(mp_s[s[i]]!=t[i]){
        //         return false;
        //     }
        //     if(mp_t.find(t[i])==mp_t.end()){
        //         mp_t.insert(pair<char,char>{t[i],s[i]});
        //     }else if(mp_t[t[i]]!=s[i]){
        //         return false;
        //     }
        // }
        // return true;
        auto width = s.size();
        vector<int> s_map(128), t_map(128);
        for (int i = 0; i != width; ++i)
        {
            if (s_map[s[i]] != t_map[t[i]])
            {
                return false;
            }
            s_map[s[i]] = i+1;
            t_map[t[i]] = i+1;
        }
        return true;
    }
};
// @lc code=end
