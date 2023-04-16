/*
 * @lc app=leetcode id=1157 lang=cpp
 *
 * [1157] Online Majority Element In Subarray
 */
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;
// @lc code=start
class MajorityChecker
{
    const vector<int> &arr;
    unordered_map<int, vector<int>> records;
    mt19937 gen{random_device{}()};

public:
    MajorityChecker(vector<int> &arr) : arr(arr)
    {
        int w = arr.size();
        for (int i = 0; i != w; ++i)
        {
            records[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold)
    {
        int w = right - left + 1;
        if (records.size() < 10)
        {
            for (auto &p : records)
            {
                int count = upper_bound(p.second.begin(), p.second.end(), right) - lower_bound(p.second.begin(), p.second.end(), left);
                if (count >= threshold)
                {
                    return p.first;
                }
            }
            return -1;
        }
        uniform_int_distribution<int> uni(left, right);
        for (int i = 0; i != 20; ++i)
        {
            int choice = uni(gen);
            vector<int> &record = records[arr[choice]];
            int count = upper_bound(record.begin(), record.end(), right) - lower_bound(record.begin(), record.end(), left);
            if (count >= threshold)
            {
                return arr[choice];
            }
            else if (count + w - threshold < threshold)
            {
                return -1;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end
