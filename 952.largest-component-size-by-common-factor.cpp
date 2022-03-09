/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
    class DSU
    {
    public:
        vector<int> parent;
        DSU(int N)
        {
            parent = vector<int>(N);
            for (int i = 0; i < N; ++i)
                parent[i] = i;
        }
        int find(int x)
        {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void union_set(int x, int y)
        {
            parent[find(x)] = find(y);
        }
    };

public:
    int largestComponentSize(vector<int> &nums)
    {
        int width = nums.size();
        vector<vector<int>> factored(width, vector<int>());
        for (int i = 0; i != width; ++i)
        {
            if (nums[i] % 2 == 0)
            {
                factored[i].push_back(2);
            }
            int n = nums[i];
            while (n % 2 == 0)
            {
                n /= 2;
            }
            int step = 3;
            while (step * step <= n)
            {
                if (n % step == 0)
                {
                    while (n % step == 0)
                    {
                        n /= step;
                    }
                    factored[i].push_back(step);
                }
                step += 2;
            }
            if (n > 1 || factored[i].empty())
            {
                factored[i].push_back(n);
            }
        }

        unordered_set<int> primes;
        for (auto &vec : factored)
        {
            for (auto p : vec)
            {
                primes.insert(p);
            }
        }
        vector<int> primesL(primes.size());
        int t = 0;
        for (auto p : primes)
        {
            primesL[t++] = p;
        }

        unordered_map<int, int> primeToInd;
        for (int i = 0; i < primes.size(); ++i)
        {
            primeToInd[primesL[i]] = i;
        }
        DSU dsu(primes.size());
        for (auto &fac : factored)
        {
            for (auto p : fac)
            {
                dsu.union_set(primeToInd[fac[0]], primeToInd[p]);
            }
        }
        vector<int> count(primes.size());
        for (auto &fac : factored)
        {
            ++count[dsu.find(primeToInd[fac[0]])];
        }
        int res = 0;
        for (int c : count)
        {
            res = max(res, c);
        }
        return res;
    }
};
// @lc code=end

// T:O(N^2) TLE
// class Solution
// {
//     int gcf(int a, int b)
//     {
//         while (a != 0 && b != 0)
//         {
//             if (a > b)
//             {
//                 a %= b;
//             }
//             else
//             {
//                 b %= a;
//             }
//         }
//         return max(a, b);
//     }
//     int find_root(int ind)
//     {
//         if (group_record[ind] != ind)
//         {
//             return find_root(group_record[ind]);
//         }
//         else
//         {
//             return ind;
//         }
//     }
//     vector<int> group_record;

// public:
//     int largestComponentSize(vector<int> &nums)
//     {
//         int width = nums.size();
//         group_record = vector<int>(width, -1);
//         for (int i = 0; i != width; ++i)
//         {
//             group_record[i] = i;
//             unordered_set<int> not_same_grp_ind;
//             for (int j = 0; j != i; ++j)
//             {
//                 int j_root_ind = group_record[find_root(j)];
//                 group_record[j] = j_root_ind;
//                 if (j_root_ind == i || not_same_grp_ind.count(j_root_ind))
//                 {
//                     continue;
//                 }
//                 else if (gcf(nums[i], nums[j]) > 1)
//                 {
//                     // not_same_grp_ind.erase(group_record[j_root_ind]);
//                     group_record[j_root_ind] = i;
//                 }
//                 else
//                 {
//                     not_same_grp_ind.insert(j_root_ind);
//                 }
//             }
//         }
//         vector<int> groups_size(width, 0);
//         for (auto n : group_record)
//         {
//             ++groups_size[find_root(n)];
//         }
//         return *max_element(groups_size.begin(), groups_size.end());
//     }
// };

// class Solution
// {
//     unordered_map<int, int> prime_group;
//     int find_root(int prime)
//     {
//         if (prime_group[prime] != prime)
//         {
//             prime_group[prime]=find_root(prime_group[prime]);
//             return prime_group[prime];
//         }
//         else
//         {
//             return prime;
//         }
//     }

// public:
//     int largestComponentSize(vector<int> &nums)
//     {
//         int width = nums.size();
//         int max_num = *max_element(nums.begin(), nums.end());
//         vector<int> prime_num = {2};
//         for (int i = 3, end_pos = max_num / 2; i <= end_pos; i += 2)
//         {
//             bool is_prime = true;
//             for (auto n : prime_num)
//             {
//                 if (i % n == 0)
//                 {
//                     is_prime = false;
//                     break;
//                 }
//             }
//             if (is_prime)
//             {
//                 prime_num.push_back(i);
//             }
//         }
//         int p_width = prime_num.size();
//         vector<int> num_group(width);

//         for (int k = 0; k != width; ++k)
//         {
//             int prime_group_root = 0;
//             for (int i = 0; i < p_width && prime_num[i] <= nums[k]; ++i)
//             {
//                 if (nums[k] % prime_num[i] == 0)
//                 {
//                     while (nums[k] % prime_num[i] == 0)
//                     {
//                         nums[k] /= prime_num[i];
//                     }
//                     if (!prime_group.count(prime_num[i]))
//                     {
//                         prime_group[prime_num[i]] = prime_num[i];
//                     }
//                     if (prime_group_root == 0)
//                     {
//                         prime_group_root = find_root(prime_num[i]);
//                         num_group[k] = prime_group_root;
//                     }
//                     else
//                     {
//                         prime_group[find_root(prime_num[i])] = prime_group_root;
//                         prime_group[prime_num[i]] = prime_group_root;
//                     }
//                 }
//             }
//             if (num_group[k] == 0)
//             {
//                 if (!prime_group.count(nums[k]))
//                 {
//                     prime_group[nums[k]] = nums[k];
//                     num_group[k] = nums[k];
//                 }
//                 else
//                 {
//                     num_group[k] = prime_group[find_root(nums[k])];
//                     prime_group[nums[k]] = num_group[k];
//                 }
//             }
//         }
//         unordered_map<int, int> prime_group_count;
//         for (auto n : num_group)
//         {
//             if (n > 1)
//             {
//                 ++prime_group_count[find_root(n)];
//             }
//         }
//         int res = 0;
//         for (auto &p : prime_group_count)
//         {
//             res = max(res, p.second);
//         }
//         return res;
//     }
// };