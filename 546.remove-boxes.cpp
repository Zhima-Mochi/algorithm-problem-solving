/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <array>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        int width = boxes.size();
        unordered_map<int, array<int, 100>> records;
        return dfs(boxes, records, 0, width - 1, 0);
    }

    int dfs(vector<int> &boxes, unordered_map<int, array<int, 100>> &records, int l, int r, int k)
    {
        if (l > r)
        {
            return 0;
        }
        int pos = (l << 10) + r;
        if (!records.count(pos))
        {
            records[pos].fill(0);
        }
        if (records[pos][k] != 0)
        {
            return records[pos][k];
        }
        int org_k = k;
        while (l < r && boxes[l] == boxes[l + 1])
        {
            ++l;
            ++k;
        }
        int res = dfs(boxes, records, l + 1, r, 0) + (k + 1) * (k + 1);
        //To connect or not to connect, that is a question.
        for (int i = l + 1; i <= r; ++i)
        {
            if (boxes[i] == boxes[l])
            {
                res = max(res, dfs(boxes, records, i, r, k + 1) + dfs(boxes, records, l + 1, i - 1, 0));
                while (i <= r && boxes[i + 1] == boxes[l])
                {
                    ++i;
                }
            }
        }
        return records[pos][org_k] = res;
    }
};
// @lc code=end
    // class Solution
    // {
    //     int width;

    // public:
    //     int removeBoxes(vector<int> &boxes)
    //     {
    //         list<pair<int, int>> vec;
    //         int boxes_width = boxes.size();
    //         int consecutive_count = 1;
    //         unordered_map<int, vector<list<pair<int, int>>::iterator>> umap;
    //         for (auto i = 1; i != boxes_width; ++i)
    //         {
    //             if (boxes[i] != boxes[i - 1])
    //             {
    //                 vec.push_back({boxes[i - 1], consecutive_count});
    //                 consecutive_count = 1;
    //                 umap[boxes[i - 1]].push_back(prev(vec.end()));
    //             }
    //             else
    //             {
    //                 ++consecutive_count;
    //             }
    //         }
    //         vec.push_back({boxes[boxes_width - 1], consecutive_count});
    //         umap[boxes[boxes_width - 1]].push_back(prev(vec.end()));
    //         //erase exist only once
    //         int base = 0;
    //         for (auto &p : umap)
    //         {

    //             if (p.second.size() == 1)
    //             {

    //                 base += p.second[0]->second * p.second[0]->second;
    //                 vec.erase(p.second[0]);
    //             }
    //         }
    //         int res = base;
    //         width = vec.size();
    //         dfs(vec, 0, res, base);
    //         return res;
    //     }
    //     void dfs(list<pair<int, int>> &vec, int current_point, int &res, int &base)
    //     {
    //         auto cur = vec.begin();
    //         while (cur != vec.end() && cur->first < 0)
    //         {
    //             ++cur;
    //         }
    //         if (cur == vec.end())
    //         {
    //             res = max(res, base + current_point);
    //             return;
    //         }

    //         while (cur != vec.end())
    //         {
    //             vector<list<pair<int, int>>::iterator> used_cur;
    //             int selected_num = cur->first;
    //             int count = 0;
    //             while (cur != vec.end() && (cur->first == selected_num || cur->first < 0))
    //             {
    //                 if (cur->first < 0)
    //                 {
    //                     ++cur;
    //                     continue;
    //                 }
    //                 used_cur.push_back(cur);
    //                 count += cur->second;
    //                 cur->first *= -1;
    //                 ++cur;
    //             }
    //             current_point += count * count;
    //             dfs(vec, current_point, res, base);
    //             current_point -= count * count;
    //             while (!used_cur.empty())
    //             {
    //                 used_cur.back()->first *= -1;
    //                 used_cur.pop_back();
    //             }
    //         }
    //     }
    // };