/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */
#include <random>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
    default_random_engine gen;
    uniform_real_distribution<double> dist = uniform_real_distribution<double>(0.0, 2.0 * M_PI);
    uniform_real_distribution<double> dist_radius = uniform_real_distribution<double>(0.0, 1.0);
    double _radius, _x_center, _y_center;

public:
    Solution(double radius, double x_center, double y_center) : _radius(radius), _x_center(x_center), _y_center(y_center)
    {
    }
    vector<double> randPoint()
    {
        double angle = dist(gen);
        double resized_radius = _radius * sqrt(dist_radius(gen)); //inverse of F(x)=x/r^2
        return {_x_center + resized_radius * sin(angle), _y_center + resized_radius * cos(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end
