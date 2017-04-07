class Solution {
public:
    bool isPrime(int n) {
        if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            return false;
        }
        
        int t = sqrt(n);
        for (int i = 6; i <= t; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    int countPrimes2(int n) {
        if (n <= 2) {
            return 0;
        } else {
            int count = 0;
            if (n <= 3)
                count = 1;
            else if (n <= 5) 
                count = 2;
            else 
                count = 3;
                
            for (int i = 6; i <  n; i++) {
                if (isPrime(i)) {
                    ++count;
                }
            }
            return count;
        }
    }
    int countPrimes(int n) {
        bool* isPrime = new bool[n];
        memset(isPrime, 1, sizeof(bool) * n);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i])    continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                ++count;
            }
        }
        
        return count;
    }
};