/*
 * @lc app=leetcode id=2512 lang=cpp
 *
 * [2512] Reward Top K Students
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        unordered_map<int, int> records;
        unordered_set<string> p, n;
        for (auto &s : positive_feedback)
        {
            p.insert(s);
        }
        for (auto &s : negative_feedback)
        {
            n.insert(s);
        }
        int len = student_id.size();
        vector<int> res;
        for (int i = 0; i != len; ++i)
        {
            res.push_back(student_id[i]);
            report[i].push_back(' ');
            int prev = 0;
            int pos = 0;
            int score = 0;
            while ((pos = report[i].find(' ', prev)) != string::npos)
            {
                string word = report[i].substr(prev, pos - prev);
                if (p.count(word))
                {
                    score += 3;
                }
                else if (n.count(word))
                {
                    score -= 1;
                }
                prev = pos + 1;
            }
            records[student_id[i]] = score;
        }
        sort(res.begin(), res.end(), [&](int a, int b)
             {
            if (records[a]==records[b]){
                return a<b;
            }else{
                return records[a]>records[b];
            } });
        res.resize(k);
        return res;
    }
};
// @lc code=end
