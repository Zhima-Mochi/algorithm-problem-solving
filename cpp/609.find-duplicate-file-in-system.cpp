/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<size_t, vector<string>> content_to_path;

        for (auto &path : paths)
        {
            int pos = 0, next_pos = path.find(' ');
            string folder_path = path.substr(pos, next_pos - pos);
            pos = next_pos;
            while (pos != path.size())
            {
                ++pos;
                next_pos = path.find('(', pos);
                string file_name = path.substr(pos, next_pos - pos);
                pos = next_pos + 1;
                next_pos = path.find(')', pos);
                size_t content_hash = hash<string>{}(path.substr(pos, next_pos - pos));
                pos = next_pos + 1;
                content_to_path[content_hash].push_back(folder_path + '/' + file_name);
            }
        }
        vector<vector<string>> res;
        for (auto &pr : content_to_path)
        {
            if (pr.second.size() > 1)
            {
                res.push_back(pr.second);
            }
        }
        return res;
    }
};

// @lc code=end

// class Solution
// {
//     static regex file_name_regex;

// public:
//     vector<vector<string>> findDuplicate(vector<string> &paths)
//     {
//         unordered_map<size_t, vector<string>> content_to_path;

//         for (auto &path : paths)
//         {
//             string folder_path = path.substr(0, path.find(' '));
//             auto word_begin = sregex_iterator(path.begin(), path.end(), file_name_regex);
//             auto word_end = sregex_iterator();
//             for (auto i = word_begin; i != word_end; ++i)
//             {
//                 auto match = *i;
//                 content_to_path[hash<string>{}(match[2].str())].push_back(folder_path + '/' + match[1].str());
//             }
//         }
//         vector<vector<string>> res;
//         for (auto &pr : content_to_path)
//         {
//             if (pr.second.size() > 1)
//             {
//                 res.push_back(pr.second);
//             }
//         }
//         return res;
//     }
// };
// regex Solution::file_name_regex = regex("(\\w+\\.?\\w*)\\((\\w*)\\)");