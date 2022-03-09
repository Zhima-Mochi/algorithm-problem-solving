/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
// @lc code=start
// dfs maximum profit method
class Solution
{
    int goods_num;
    string origin;

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        goods_num = price.size();
        origin = string(goods_num, 0);
        int normal_cost = 0;
        for (int i = 0; i != goods_num; ++i)
        {
            normal_cost += price[i] * needs[i];
        }
        vector<pair<string, int>> special_vec;
        for (auto &spec : special)
        {
            pair<string, int> p;
            int net_profit = 0;
            for (int i = 0; i != goods_num; ++i)
            {
                net_profit += price[i] * spec[i];
            }
            net_profit -= spec.back();
            if (net_profit <= 0)
            {
                continue;
            }
            p.first = vec_to_string(spec);
            p.second = net_profit;
            special_vec.push_back(p);
        }
        int max_profit = 0;
        dfs(max_profit, special_vec, vec_to_string(needs), 0);
        return normal_cost - max_profit;
    }
    void dfs(int &res, vector<pair<string, int>> &special_vec, string status, int profit)
    {
        for (auto &spec : special_vec)
        {
            auto next_status = str_subtraction(status, spec.first);
            if (next_status == "")
            {
                res = max(res, profit);
            }
            else
            {
                dfs(res, special_vec, next_status, profit + spec.second);
            }
        }
    }
    string vec_to_string(vector<int> &vec)
    {
        string res;
        for (int i = 0; i != goods_num; ++i)
        {
            res.push_back(vec[i]);
        }
        return res;
    }
    string str_subtraction(const string &l, const string &r)
    {
        string res;
        for (int i = 0; i != goods_num; ++i)
        {
            res.push_back(l[i] - r[i]);
            if (res.back() < 0)
            {
                return "";
            }
        }
        return res;
    }
};
// @lc code=end

// TLE
// class Solution
// {
//     int goods_num;

// public:
//     int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
//     {
//         goods_num = price.size();
//         unordered_map<string, int> bundle_cost;
//         for (int i = 0; i != goods_num; ++i)
//         {
//             vector<int> one_price = vector<int>(goods_num + 1);
//             one_price[i] = 1;
//             one_price.back() = price[i];
//             special.push_back(one_price);
//         }
//         unordered_set<string> candidates;
//         candidates.insert(vec_to_string(needs));
//         bundle_cost[vec_to_string(needs)] = 0;
//         string origin = string(goods_num, 0);
//         vector<pair<string, int>> special_vec;
//         for (auto &spec : special)
//         {
//             pair<string, int> p;
//             p.first = vec_to_string(spec);
//             p.second = spec.back();
//             special_vec.push_back(p);
//         }
//         while (!candidates.empty())
//         {
//             unordered_set<string> next_candidates;
//             for (auto &candidate : candidates)
//             {
//                 for (auto &spec : special_vec)
//                 {
//                     auto new_bundle = str_subtraction(candidate, spec.first);
//                     if (new_bundle == candidate || new_bundle == "")
//                     {
//                         continue;
//                     }

//                     if (bundle_cost.count(new_bundle))
//                     {
//                         if (bundle_cost[new_bundle] > bundle_cost[candidate] + spec.second)
//                         {
//                             bundle_cost[new_bundle] = bundle_cost[candidate] + spec.second;
//                             if (new_bundle != origin)
//                             {
//                                 next_candidates.insert(new_bundle);
//                             }
//                         }
//                     }
//                     else
//                     {
//                         bundle_cost[new_bundle] = bundle_cost[candidate] + spec.second;
//                         if (new_bundle != origin)
//                         {
//                             next_candidates.insert(new_bundle);
//                         }
//                     }
//                 }
//             }
//             candidates = next_candidates;
//         }
//         return bundle_cost[origin];
//     }
//     string vec_to_string(vector<int> &vec)
//     {
//         string res;
//         for (int i = 0; i != goods_num; ++i)
//         {
//             res.push_back(vec[i]);
//         }
//         return res;
//     }
//     string str_subtraction(const string &l, const string &r)
//     {
//         string res;
//         for (int i = 0; i != goods_num; ++i)
//         {
//             res.push_back(l[i] - r[i]);
//             if (res.back() < 0)
//             {
//                 return "";
//             }
//         }
//         return res;
//     }
// };