import java.util.Arrays;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;

/*
* @lc app=leetcode id=451 lang=java
*
* [451] Sort Characters By Frequency
*/

// @lc code=start
import java.text.CharacterIterator;
import java.text.StringCharacterIterator;

class Solution {
    public String frequencySort(String s) {
        int[] count = new int[128];
        CharacterIterator it = new StringCharacterIterator(s);
        while (it.current() != CharacterIterator.DONE) {
            ++count[it.current()];
            it.next();
        }
        for (int i = 0; i != 128; ++i) {
            if (count[i] > 0) {
                count[i] *= 128;
                count[i] += i;
            }
        }
        Arrays.sort(count);
        StringBuilder s2 = new StringBuilder();
        for (int i = 127; i >= 0; --i) {
            var freq = count[i] >> 7;
            var ch = (char) (count[i] & 127);
            for (int j = 0; j < freq; ++j) {
                s2.append(ch);
            }
        }
        return s2.toString();
    }
}
// @lc code=end
// class Solution
// {
// public:
// string frequencySort(string s)
// {
// vector<int> count(128);
// for (auto c : s)
// {
// ++count[c];
// }
// auto comp = [](const pair<char, int> &l, const pair<char, int> &r)
// {
// return l.second < r.second;
// };
// priority_queue<pair<char, int>,
// vector<pair<char, int>>, decltype(comp)>
// pq(comp);
// for (int i = 0; i != 128; ++i)
// {
// if (count[i] > 0)
// {
// pq.push({i, count[i]});
// }
// }
// auto pos = 0;
// while (!pq.empty())
// {
// auto &elem = pq.top();
// for (int i = 0; i != elem.second; ++i)
// {
// s[pos++] = elem.first;
// }
// pq.pop();
// }
// return s;
// }
// };