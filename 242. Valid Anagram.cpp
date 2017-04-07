 class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        if (!s.empty() && !t.empty()) {
            const int N =  128;
       	auto cvec = new char[N];
       	memset(cvec + 'a' - 1 , 0, sizeof(char) * (N - 'a'));
       
        for (auto const& ch : s) {
            ++cvec[ch ];
        }
   
        for (auto const& ch : t) {
           --cvec[ch ];
        }
        
        for (auto i = 'a'; i <=  'z'; i++) {
            if (cvec[i] != 0) {
                cout << i << endl;
                return false;
            }
        } 
        
        }
        return true;
    }
};