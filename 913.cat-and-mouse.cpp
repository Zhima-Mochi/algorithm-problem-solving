/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, int> turn_record;
    unordered_set<int> past_states;
    unordered_set<int> draw_states;

public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        return helpler(graph, true, 1, 2);
    }
    int helpler(vector<vector<int>> &graph, bool is_mouse, int mouse_pos, int cat_pos)
    {
        if (mouse_pos == cat_pos)
        {
            return 2;
        }
        if (mouse_pos == 0)
        {
            return 1;
        }

        int key = (mouse_pos << 10) + (cat_pos << 1) + is_mouse;
        if (past_states.count(key))
        {
            draw_states.insert(key);
            return 0;
        }
        if (turn_record.count(key))
        {
            if (is_mouse && turn_record[key] == 2 || !is_mouse && turn_record[key] == 1)
            {
                if (draw_states.count(key))
                {
                    return 0;
                }
            }
            return turn_record[key];
        }

        past_states.insert(key);
        bool has_draw = false;
        bool has_opposite = false;
        if (is_mouse)
        {
            for (auto next_pos : graph[mouse_pos])
            {
                int future = helpler(graph, !is_mouse, next_pos, cat_pos);
                if (future == 1)
                {
                    turn_record[key] = 1;
                    past_states.erase(key);
                    return 1;
                }
                else if (future == 0)
                {
                    has_draw = true;
                }
                else
                {
                    has_opposite = true;
                }
            }
        }
        else
        {
            for (auto next_pos : graph[cat_pos])
            {
                if (next_pos == 0)
                {
                    continue;
                }
                int future = helpler(graph, !is_mouse, mouse_pos, next_pos);
                if (future == 2)
                {
                    turn_record[key] = 2;
                    past_states.erase(key);
                    return 2;
                }
                else if (future == 0)
                {
                    has_draw = true;
                }
                else
                {
                    has_opposite = true;
                }
            }
        }
        past_states.erase(key);
        if (has_opposite)
        {
            turn_record[key] = is_mouse ? 2 : 1;
        }
        if (has_draw)
        {
            return 0;
        }
        return turn_record[key];
    }
};
// @lc code=end
