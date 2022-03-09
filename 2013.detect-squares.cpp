/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class DetectSquares
{
    unordered_map<int, int> pos_count;
    unordered_map<int, unordered_set<int>> x_to_all_y;
    vector<pair<int, int>> direction1 = {{1, 0}, {1, 1}}, direction2 = {{-1, 0}, {-1, 1}};

public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        ++pos_count[(point[0] << 10) + point[1]];
        x_to_all_y[point[0]].insert(point[1]);
    }

    int count(vector<int> point)
    {
        int res = 0;
        for (auto y : x_to_all_y[point[0]])
        {
            int diff = y - point[1];
            if (diff == 0)
            {
                continue;
            }
            res += get_square_cnt(point, diff);
        }
        return res;
    }
    int get_square_cnt(vector<int> &point, int diff)
    {
        int res = 0;
        int cnt_base = pos_count[(point[0] << 10) + point[1] + diff];
        int cnt = 1;
        for (auto [a, b] : direction1)
        {
            int x = point[0] + a * diff;
            int y = point[1] + b * diff;
            if (x >= 0 && y >= 0 && pos_count.count((x << 10) + y))
            {
                cnt *= pos_count[(x << 10) + y];
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        res += cnt * cnt_base;
        cnt = 1;
        for (auto [a, b] : direction2)
        {
            int x = point[0] + a * diff;
            int y = point[1] + b * diff;
            if (x >= 0 && y >= 0 && pos_count.count((x << 10) + y))
            {
                cnt *= pos_count[(x << 10) + y];
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        res += cnt * cnt_base;
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end
