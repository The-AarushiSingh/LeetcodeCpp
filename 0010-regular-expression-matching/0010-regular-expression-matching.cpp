#include <string>
#include <vector>
using namespace std;

class Solution {
    string s, p;
    vector<vector<int>> memo;

    bool match(int i, int j) {
        int& cached = memo[i][j];
        if (cached != -1) return cached;
        bool ans;
        if (j == static_cast<int>(p.size())) {
            ans = i == static_cast<int>(s.size());
        } else {
            bool first = i < static_cast<int>(s.size())
                && (s[i] == p[j] || p[j] == '.');
            if (j + 1 < static_cast<int>(p.size()) && p[j + 1] == '*') {
                ans = match(i, j + 2) || (first && match(i + 1, j));
            } else {
                ans = first && match(i + 1, j + 1);
            }
        }
        cached = ans;
        return ans;
    }

public:
    bool isMatch(string text, string pattern) {
        s = text;
        p = pattern;
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return match(0, 0);
    }
};