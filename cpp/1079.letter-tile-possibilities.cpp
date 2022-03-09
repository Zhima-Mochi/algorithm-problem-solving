/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
// t:O(N!), s:O(N!)
class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int w = tiles.size();
        unordered_map<string, int> records;
        string rest(26, 0);
        for (auto c : tiles)
        {
            ++rest[c - 'A'];
        }
        function<int(string &)> dp = [&](string &rest)
        {
            if (records.count(rest))
            {
                return records[rest];
            }
            int res = 0;
            for (int i = 0; i != 26; ++i)
            {
                if (rest[i])
                {
                    --rest[i];
                    ++res;
                    res += dp(rest);
                    ++rest[i];
                }
            }
            return records[rest] = res;
        };
        return dp(rest);
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int numTilePossibilities(string tiles)
//     {
//         int w = tiles.size();
//         unordered_set<string> collection;
//         function<void(string &, int, int)> dp = [&](string &tiles, int left, int right)
//         {
//             if (left == right)
//             {
//                 collection.insert(tiles);
//                 return;
//             }
//             for (int i = left; i != right; ++i)
//             {
//                 swap(tiles[left], tiles[i]);
//                 dp(tiles, left + 1, right);
//                 swap(tiles[left], tiles[i]);
//             }
//         };
//         dp(tiles, 0, w);
//         int res = collection.size();
//         for (int i = 1; i != w; ++i)
//         {
//             unordered_set<string> next;
//             for (auto str : collection)
//             {
//                 str.pop_back();
//                 next.insert(str);
//             }
//             res += next.size();
//             collection = move(next);
//         }
//         return res;
//     }
// };