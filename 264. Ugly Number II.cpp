class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) {
            return 1;
        }
        
        int k2 = 0;
        int k3 = 0;
        int k5 = 0;
        
        vector<long long> ivec(n);
        ivec[0] = 1;
        
        for (int i = 1; i < n; i++) {
            ivec[i] = min(ivec[k2] * 2, min(ivec[k3]* 3, ivec[k5] * 5));
            if (ivec[i] == ivec[k2] * 2)  k2++;
            if (ivec[i] == ivec[k3] * 3)  k3++;
            if (ivec[i] == ivec[k5] * 5)  k5++;
        }
        
        return ivec[n - 1];
    }
};