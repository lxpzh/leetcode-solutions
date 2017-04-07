class Solution {
public:
    int numTrees(int n) {
        vector<int> ivec(n + 1                                   );
        ivec[0] = 1;
        ivec[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += ivec[j] * ivec[i-j-1];
            }
            ivec[i] = sum;
        }
        
        return ivec[n];
    }
};