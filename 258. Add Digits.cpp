class Solution {
public:
    vector<int> getAllDigits(int num) {
        vector<int> allDigits;
        allDigits.reserve(12);
        
        while (num != 0) {
            allDigits.push_back(num % 10);
            num /= 10;
        }
        
        return allDigits;
    }
    
    int addDigits(int num) {
        if (num < 10) {
            return num;
        } 
        else {
            auto allDigitsVec = getAllDigits(num);
            int result = 0;
            
            for (auto const& i : allDigitsVec) {
                result += i;    
            }
           
            return addDigits(result);
        }
        
    }
};