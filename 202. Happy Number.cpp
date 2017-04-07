class Solution {
public:
    inline int square(int n) {
        return n*n;
    }
    
    int digitsSquareSum(int n) {
        int sum = 0;
        
        while (n) {
            int remainder = n % 10;
            sum += square(remainder);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
         vector<char> s(1000 , 0);
         if (n < 1000)
            s[n] = 1;

          while (n != 1) {
            n = digitsSquareSum(n);
            if (s[n] == 0) {
                s[n] = 1;
            } else {
                return false;
            }
            cout << n << endl;
            
        }
        
        return true;
    }
};