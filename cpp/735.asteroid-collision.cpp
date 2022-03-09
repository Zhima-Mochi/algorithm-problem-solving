/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> aster_stack;
        for (auto n : asteroids)
        {
            while (!aster_stack.empty() && aster_stack.back() > 0 && n < 0)
            {
                if (aster_stack.back() < -n)
                {
                    aster_stack.pop_back();
                }
                else
                {
                    break;
                }
            }
            if (aster_stack.empty())
            {
                aster_stack.push_back(n);
            }
            else
            {
                if (n > 0 || aster_stack.back() < 0)
                {
                    aster_stack.push_back(n);
                }
                else if (aster_stack.back() == -n)
                {
                    aster_stack.pop_back();
                }
            }
        }
        return aster_stack;
    }
};
// @lc code=end
