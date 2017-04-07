class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        
        if (num1.size() < num2.size()) {
            num1.swap(num2);
        }
        
        int i = num1.size() - 1;
        int flag = 0;
        for (int j = num2.size() - 1; i >= 0 && j >= 0 ; i--, j--) {
            int sum = num1[i] - '0' + num2[j] - '0' + flag;
            
            flag = (sum >= 10);
            if (sum >= 10) {
                sum = sum -10;
            }
 
            result.push_back(sum + '0');
        }
        
        while (i >= 0) {
            int sum = num1[i--] - '0' + flag;
            flag = (sum >= 10);
            if (sum >= 10) {
                sum = sum -10;
            }
 
            result.push_back(sum + '0');
        }
        if (flag == 1) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};