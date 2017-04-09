class Solution {
public:
    vector<int> getAllSpuares(int n)
    {
        vector<int> result;
        for (int i = 1; i * i <= n; i++) 
        {
            result.push_back(i * i);
        }    
        
        return result;
    }
    
    int numSquares(int n) {
        vector<int> squares = getAllSpuares(n);
        vector<int> result(n+1);
       
        result[0] = 0;
        for (int i= 1 ; i <= n; i++) 
        {
            int minTimes = 0x7ffffff;
            for (auto j : squares) 
            {
                if (i >= j)
                {
                    minTimes = min(minTimes, result[i - j] + 1);
                }
                else 
                {
                    break;
                }
            }
            
            result[i] = minTimes;
        }
        
        return result[n];
    }
};