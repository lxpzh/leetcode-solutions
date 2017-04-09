class Solution {
public:
    int myAtoi(string str) {
        auto iter = str.begin();
        
        // skip white space 
        while (isspace(*iter)) 
        {
            ++iter;
        }
        
        int sign = 1;
        if (*iter == '+') 
        {
            ++iter;
        }
        else if (*iter == '-') 
        {
            ++iter;
            sign = -1;
        }
       
        int sum = 0;
        for (; iter != str.end() && isdigit(*iter); ++iter) 
        {
            if (sum > INT_MAX / 10 || sum == INT_MAX / 10 && *iter > '7') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            sum = sum * 10 + *iter - '0';
        }
     
        return sign * sum;
    }
};