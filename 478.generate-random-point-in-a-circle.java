/*
 * @lc app=leetcode id=478 lang=java
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
class Solution {
    public double _radius, _x_center, _y_center;

    public Solution(double radius, double x_center, double y_center) {
        _radius = radius;
        _x_center = x_center;
        _y_center = y_center;
    }

    public double[] randPoint() {
        double angle = Math.random() * 2 * Math.PI;
        double resized_radius = _radius * Math.sqrt(Math.random());
        return new double[] { _x_center + resized_radius * Math.sin(angle),
                _y_center + resized_radius * Math.cos(angle) };
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(radius, x_center, y_center); double[] param_1 = obj.randPoint();
 */
// @lc code=end
