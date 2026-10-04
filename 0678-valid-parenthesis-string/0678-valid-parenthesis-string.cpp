class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open.push(i);
            }
            else if (s[i] == '*') {
                star.push(i);
            }
            else { // ')'

                // First try to match with '('
                if (!open.empty()) {
                    open.pop();
                }
                // Otherwise use '*' as '('
                else if (!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*' after them
        while (!open.empty() && !star.empty()) {
            if (open.top() > star.top()) {
                // '*' occurs before '(' -> cannot match
                return false;
            }

            open.pop();
            star.pop();
        }

        // Unmatched '(' remain
        return open.empty();
    }
};