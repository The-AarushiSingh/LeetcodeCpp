class Solution {
public:
    int maxDepth(string s) {
        int openBrackets=0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                openBrackets++;
                ans = max(ans, openBrackets);
            }
            else if (ch == ')') {
                openBrackets--;
            }
        }

        return ans;
    }
};