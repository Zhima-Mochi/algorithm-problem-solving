/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class TopVotedCandidate
{
    vector<int> votes_record;
    vector<int> times_;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        vector<short> vote(5001);
        int current_high = 0;
        int current_win = 0;
        for (int i = 0, width = persons.size(); i != width; ++i)
        {
            ++vote[persons[i]];
            if (vote[persons[i]] >= current_high)
            {
                current_high = vote[persons[i]];
                current_win = persons[i];
            }
            persons[i] = current_win;
        }
        votes_record = persons;
        times_ = times;
    }

    int q(int t)
    {
        auto ind = lower_bound(times_.begin(), times_.end(), t) - times_.begin();
        if (ind == times_.size() || times_[ind] > t)
        {
            --ind;
        }
        return votes_record[ind];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
