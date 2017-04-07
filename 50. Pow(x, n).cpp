class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return (1 / (myPow(x, -n-1) * x));
        else 
            return powFuncNoRecursive(x, n);
    }
    double powFunc(double x, int n) {
        if (n == 0)
            return 1;
        else if (n == 1) {
            return x;
        } else {
            double re = powFunc(x, n/2);
            if (n % 2 == 1)
                return re * re * x;
            else
                return re * re;
        }
    }
    double powFuncNoRecursive(double x, int n) {
        double result = 1;
        
        while (n) {
            if (n & 1 == 1)
                result *= x;
            x *= x;
            n >>= 1;
        }
        
        return result;
    }
};