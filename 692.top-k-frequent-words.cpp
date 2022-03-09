/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> w_count;
        for (auto &w : words)
        {
            ++w_count[w];
        }
        auto comp = [](pair<string, int> &l, pair<string, int> &r)
        {
            if (l.second > r.second)
            {
                return true;
            }
            else if (l.second == r.second && l.first < r.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        vector<pair<string, int>> heap_vector;
        for (auto &p : w_count)
        {
            heap_vector.push_back(p);
            if (heap_vector.size() == k + 1)
            {
                make_heap(heap_vector.begin(), heap_vector.end(), comp);
                pop_heap(heap_vector.begin(), heap_vector.end(), comp);
                heap_vector.pop_back();
            }
        }
        sort(heap_vector.begin(), heap_vector.end(), comp);
        vector<string> res;
        for (auto &p : heap_vector)
        {
            res.push_back(p.first);
        }
        return res;
    }
};
// @lc code=end
