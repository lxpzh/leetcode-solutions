class Solution {
public:
    bool isOp(const string& s) {
        return (s == "+" || s== "-" ||s == "*" || s == "/");
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> numberStack;
        
        for (const auto& s : tokens) {
            if (isOp(s)) {
                auto num1 = numberStack.top();
                numberStack.pop();
                auto num2 = numberStack.top();
                numberStack.pop();
                int result;
                
                if (s == "+") {
                    result = num1 + num2;    
                } else if (s == "-") {
                    result = num2 - num1; 
                } else if (s == "*") {
                    result = num1 * num2; 
                } else if (s == "/") {
                    result = num2 / num1; 
                    cout << result << endl;
                } 
                
                numberStack.push(result);
            }
            else {
                int num = atoi(s.c_str());
                numberStack.push(num);
            }
        }
         
        return numberStack.top();
    }
};