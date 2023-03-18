/*
 * @lc app=leetcode id=2383 lang=cpp
 *
 * [2383] Minimum Hours of Training to Win a Competition
 */
#include <vector>
using namespace std;
// @lc code=start
// time complexity: O(n), space complexity: O(1)
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int currentEnergy = initialEnergy;
        int currentExperience = initialExperience;
        int w = energy.size();
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (currentEnergy <= energy[i])
            {
                // if current energy is less than the energy needed to finish the ith task,
                // we have to increase the current energy to the needed energy
                // and it costs energy[i] - currentEnergy + 1 hours
                res += energy[i] - currentEnergy + 1;
                currentEnergy = energy[i] + 1;
            }
            if (currentExperience <= experience[i])
            {
                // if current experience is less than the experience needed to finish the ith task,
                // we have to increase the current experience to the needed experience
                // and it costs experience[i] - currentExperience + 1 hours
                res += experience[i] - currentExperience + 1;
                currentExperience = experience[i] + 1;
            }
            // after we finish the ith task,
            // we get experience[i] experience points and lose energy[i] energy points
            currentExperience += experience[i];
            currentEnergy -= energy[i];
        }
        return res;
    }
};
// @lc code=end
