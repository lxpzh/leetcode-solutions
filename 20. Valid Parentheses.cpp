class Solution {
public:
    bool isValid(string s) {
        stack<char> chStack;
        unordered_map<char, char> m { { '[' , ']' }, 
                                     { '(' , ')' }, 
                                     { '{' , '}' } };
        
        for (char ch : s) {
            if (ch == '[' || ch == '(' || ch == '{') {
                chStack.push(ch);
            } else if (ch == ']' || ch == ')' || ch == '}') {
                if (!chStack.empty() && m[chStack.top()] == ch) {
                    chStack.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        cout << s << endl;
        return chStack.empty();
    }
};