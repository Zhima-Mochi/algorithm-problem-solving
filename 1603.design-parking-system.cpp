/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */
#include <array>
using namespace std;
// @lc code=start
class ParkingSystem
{
    array<int, 3> max_capacity;
    array<int, 3> num;

public:
    ParkingSystem(int big, int medium, int small)
    {
        max_capacity[0] = big;
        max_capacity[1] = medium;
        max_capacity[2] = small;
        num.fill(0);
    }

    bool addCar(int carType)
    {
        if (num[carType - 1] < max_capacity[carType - 1])
        {
            ++num[carType - 1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
